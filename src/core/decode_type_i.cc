#include "decoder_internal.h"

#include "rviss/isa/addi.h"
#include "rviss/isa/addiw.h"
#include "rviss/isa/andi.h"
#include "rviss/isa/csrrc.h"
#include "rviss/isa/csrrci.h"
#include "rviss/isa/csrrs.h"
#include "rviss/isa/csrrsi.h"
#include "rviss/isa/csrrw.h"
#include "rviss/isa/csrrwi.h"
#include "rviss/isa/ebreak.h"
#include "rviss/isa/ecall.h"
#include "rviss/isa/fence.h"
#include "rviss/isa/fence_i.h"
#include "rviss/isa/jalr.h"
#include "rviss/isa/lb.h"
#include "rviss/isa/lbu.h"
#include "rviss/isa/ld.h"
#include "rviss/isa/lh.h"
#include "rviss/isa/lhu.h"
#include "rviss/isa/lw.h"
#include "rviss/isa/lwu.h"
#include "rviss/isa/mret.h"
#include "rviss/isa/ori.h"
#include "rviss/isa/register.h"
#include "rviss/isa/sfence_vma.h"
#include "rviss/isa/slli.h"
#include "rviss/isa/slliw.h"
#include "rviss/isa/slti.h"
#include "rviss/isa/sltiu.h"
#include "rviss/isa/srai.h"
#include "rviss/isa/sraiw.h"
#include "rviss/isa/sret.h"
#include "rviss/isa/srli.h"
#include "rviss/isa/srliw.h"
#include "rviss/isa/uret.h"
#include "rviss/isa/wfi.h"
#include "rviss/isa/xori.h"

namespace {

Register decode_register(uint32_t bits) {
    return static_cast<Register>(bits & 0x1fU);
}

uint16_t decode_imm_i(uint32_t encoded_instruction) {
    return static_cast<uint16_t>((encoded_instruction >> 20U) & 0x0fffU);
}

}

std::unique_ptr<Instruction> decode_type_i(uint32_t encoded_instruction) {
    const uint32_t opcode = encoded_instruction & 0x7fU;
    const uint32_t funct3 = (encoded_instruction >> 12U) & 0x7U;
    const Register rd = decode_register(encoded_instruction >> 7U);
    const Register rs1 = decode_register(encoded_instruction >> 15U);
    const Register rs2 = decode_register(encoded_instruction >> 20U);
    const uint16_t imm = decode_imm_i(encoded_instruction);

    switch (opcode) {
    case 0x13U:
        switch (funct3) {
        case 0b000U:
            return std::make_unique<ADDI>(rd, rs1, imm);
        case 0b010U:
            return std::make_unique<SLTI>(rd, rs1, imm);
        case 0b011U:
            return std::make_unique<SLTIU>(rd, rs1, imm);
        case 0b100U:
            return std::make_unique<XORI>(rd, rs1, imm);
        case 0b110U:
            return std::make_unique<ORI>(rd, rs1, imm);
        case 0b111U:
            return std::make_unique<ANDI>(rd, rs1, imm);
        case 0b001U:
            if ((imm & 0x0fc0U) == 0U) {
                return std::make_unique<SLLI>(rd, rs1, imm);
            }

            return nullptr;
        case 0b101U:
            if ((imm & 0x0fc0U) == 0U) {
                return std::make_unique<SRLI>(rd, rs1, imm);
            }

            if ((imm & 0x0fc0U) == 0x0400U) {
                return std::make_unique<SRAI>(rd, rs1, imm);
            }

            return nullptr;
        default:
            return nullptr;
        }
    case 0x03U:
        switch (funct3) {
        case 0b000U:
            return std::make_unique<LB>(rd, rs1, imm);
        case 0b001U:
            return std::make_unique<LH>(rd, rs1, imm);
        case 0b010U:
            return std::make_unique<LW>(rd, rs1, imm);
        case 0b011U:
            return std::make_unique<LD>(rd, rs1, imm);
        case 0b100U:
            return std::make_unique<LBU>(rd, rs1, imm);
        case 0b101U:
            return std::make_unique<LHU>(rd, rs1, imm);
        case 0b110U:
            return std::make_unique<LWU>(rd, rs1, imm);
        default:
            return nullptr;
        }
    case 0x67U:
        if (funct3 == 0b000U) {
            return std::make_unique<JALR>(rd, rs1, imm);
        }

        return nullptr;
    case 0x0fU:
        if (funct3 == 0b000U) {
            return std::make_unique<FENCE>(imm);
        }

        if (funct3 == 0b001U) {
            return std::make_unique<FENCE_I>();
        }

        return nullptr;
    case 0x73U:
        switch (funct3) {
        case 0b000U:
            if (imm == 0x000U) {
                return std::make_unique<ECALL>();
            }

            if (imm == 0x001U) {
                return std::make_unique<EBREAK>();
            }

            if (imm == 0x002U) {
                return std::make_unique<URET>();
            }

            if (imm == 0x102U) {
                return std::make_unique<SRET>();
            }

            if (imm == 0x302U) {
                return std::make_unique<MRET>();
            }

            if (imm == 0x105U) {
                return std::make_unique<WFI>();
            }

            if (((encoded_instruction >> 25U) & 0x7fU) == 0b0001001U && rd == Register::zero) {
                return std::make_unique<SFENCE_VMA>(rs1, rs2);
            }

            return nullptr;
        case 0b001U:
            return std::make_unique<CSRRW>(rd, rs1, imm);
        case 0b010U:
            return std::make_unique<CSRRS>(rd, rs1, imm);
        case 0b011U:
            return std::make_unique<CSRRC>(rd, rs1, imm);
        case 0b101U:
            return std::make_unique<CSRRWI>(rd, rs1, imm);
        case 0b110U:
            return std::make_unique<CSRRSI>(rd, rs1, imm);
        case 0b111U:
            return std::make_unique<CSRRCI>(rd, rs1, imm);
        default:
            return nullptr;
        }
    case 0x1bU:
        switch (funct3) {
        case 0b000U:
            return std::make_unique<ADDIW>(rd, rs1, imm);
        case 0b001U:
            if ((imm & 0x0fe0U) == 0U) {
                return std::make_unique<SLLIW>(rd, rs1, imm);
            }

            return nullptr;
        case 0b101U:
            if ((imm & 0x0fe0U) == 0U) {
                return std::make_unique<SRLIW>(rd, rs1, imm);
            }

            if ((imm & 0x0fe0U) == 0x0400U) {
                return std::make_unique<SRAIW>(rd, rs1, imm);
            }

            return nullptr;
        default:
            return nullptr;
        }
    default:
        return nullptr;
    }
}

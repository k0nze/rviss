# RV64GC Instruction Index

This document lists the standard unprivileged `RV64GC` instructions, grouped first by decoding type and then by RISC-V ISA extension.

`RV64GC` is treated here as:
- `RV64I`
- `M`
- `A`
- `F`
- `D`
- `C`
- `Zicsr`
- `Zifencei`

Notes:
- This document lists real ISA instructions, not assembler pseudoinstructions.
- Privileged instructions such as `MRET`, `SRET`, `WFI`, and `SFENCE.VMA` are not part of `RV64GC`.
- Compressed instructions are grouped by compressed decode format (`CR`, `CI`, `CIW`, `CL`, `CS`, `CA`, `CB`, `CJ`, `CSS`).
- Some compressed instructions are only valid in `RV64C` and are marked accordingly.
- Some compressed floating-point load/store instructions require the `D` extension and are marked accordingly.

Primary source:
- RISC-V Unprivileged ISA Manual: <https://docs.riscv.org/reference/isa/_attachments/riscv-unprivileged.pdf>

## 32-bit Instruction Formats

### U-type

#### RV64I
- `LUI`
- `AUIPC`

### J-type

#### RV64I
- `JAL`

### B-type

#### RV64I
- `BEQ`
- `BNE`
- `BLT`
- `BGE`
- `BLTU`
- `BGEU`

### S-type

#### RV64I
- `SB`
- `SH`
- `SW`
- `SD`

#### F
- `FSW`

#### D
- `FSD`

### I-type

#### RV64I
- `JALR`
- `LB`
- `LH`
- `LW`
- `LBU`
- `LHU`
- `LWU`
- `LD`
- `ADDI`
- `SLTI`
- `SLTIU`
- `XORI`
- `ORI`
- `ANDI`
- `SLLI`
- `SRLI`
- `SRAI`
- `ADDIW`
- `SLLIW`
- `SRLIW`
- `SRAIW`
- `FENCE`
- `ECALL`
- `EBREAK`

#### Zifencei
- `FENCE.I`

#### Zicsr
- `CSRRW`
- `CSRRS`
- `CSRRC`
- `CSRRWI`
- `CSRRSI`
- `CSRRCI`

#### F
- `FLW`

#### D
- `FLD`

### R-type

#### RV64I
- `ADD`
- `SUB`
- `SLL`
- `SLT`
- `SLTU`
- `XOR`
- `SRL`
- `SRA`
- `OR`
- `AND`
- `ADDW`
- `SUBW`
- `SLLW`
- `SRLW`
- `SRAW`

#### M
- `MUL`
- `MULH`
- `MULHSU`
- `MULHU`
- `DIV`
- `DIVU`
- `REM`
- `REMU`
- `MULW`
- `DIVW`
- `DIVUW`
- `REMW`
- `REMUW`

#### F
- `FADD.S`
- `FSUB.S`
- `FMUL.S`
- `FDIV.S`
- `FSQRT.S`
- `FSGNJ.S`
- `FSGNJN.S`
- `FSGNJX.S`
- `FMIN.S`
- `FMAX.S`
- `FCVT.W.S`
- `FCVT.WU.S`
- `FCVT.L.S`
- `FCVT.LU.S`
- `FCVT.S.W`
- `FCVT.S.WU`
- `FCVT.S.L`
- `FCVT.S.LU`
- `FMV.X.W`
- `FMV.W.X`
- `FEQ.S`
- `FLT.S`
- `FLE.S`
- `FCLASS.S`

#### D
- `FADD.D`
- `FSUB.D`
- `FMUL.D`
- `FDIV.D`
- `FSQRT.D`
- `FSGNJ.D`
- `FSGNJN.D`
- `FSGNJX.D`
- `FMIN.D`
- `FMAX.D`
- `FCVT.S.D`
- `FCVT.D.S`
- `FCVT.W.D`
- `FCVT.WU.D`
- `FCVT.L.D`
- `FCVT.LU.D`
- `FCVT.D.W`
- `FCVT.D.WU`
- `FCVT.D.L`
- `FCVT.D.LU`
- `FMV.X.D`
- `FMV.D.X`
- `FEQ.D`
- `FLT.D`
- `FLE.D`
- `FCLASS.D`

### R4-type

#### F
- `FMADD.S`
- `FMSUB.S`
- `FNMSUB.S`
- `FNMADD.S`

#### D
- `FMADD.D`
- `FMSUB.D`
- `FNMSUB.D`
- `FNMADD.D`

### AMO-type

#### A
- `LR.W`
- `SC.W`
- `AMOSWAP.W`
- `AMOADD.W`
- `AMOXOR.W`
- `AMOAND.W`
- `AMOOR.W`
- `AMOMIN.W`
- `AMOMAX.W`
- `AMOMINU.W`
- `AMOMAXU.W`
- `LR.D`
- `SC.D`
- `AMOSWAP.D`
- `AMOADD.D`
- `AMOXOR.D`
- `AMOAND.D`
- `AMOOR.D`
- `AMOMIN.D`
- `AMOMAX.D`
- `AMOMINU.D`
- `AMOMAXU.D`

## 16-bit Compressed Instruction Formats

### CIW

#### C
- `C.ADDI4SPN`

### CL

#### C
- `C.LW`
- `C.LD` (`RV64C` only)

#### C with D support
- `C.FLD`

### CS

#### C
- `C.SW`
- `C.SD` (`RV64C` only)

#### C with D support
- `C.FSD`

### CI

#### C
- `C.NOP`
- `C.ADDI`
- `C.LI`
- `C.LUI`
- `C.ADDI16SP`
- `C.SLLI`
- `C.LWSP`

#### C, RV64C only
- `C.ADDIW`
- `C.LDSP`

#### C with D support
- `C.FLDSP`

### CSS

#### C
- `C.SWSP`

#### C, RV64C only
- `C.SDSP`

#### C with D support
- `C.FSDSP`

### CR

#### C
- `C.JR`
- `C.MV`
- `C.EBREAK`
- `C.JALR`
- `C.ADD`

### CA

#### C
- `C.SUB`
- `C.XOR`
- `C.OR`
- `C.AND`

#### C, RV64C only
- `C.SUBW`
- `C.ADDW`

### CB

#### C
- `C.SRLI`
- `C.SRAI`
- `C.ANDI`
- `C.BEQZ`
- `C.BNEZ`

### CJ

#### C
- `C.J`

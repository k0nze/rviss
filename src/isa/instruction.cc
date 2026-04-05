#include "rvsim/isa/instruction.h"

Instruction::Instruction(Opcode opcode) : opcode(opcode) {}

Instruction::~Instruction() = default;

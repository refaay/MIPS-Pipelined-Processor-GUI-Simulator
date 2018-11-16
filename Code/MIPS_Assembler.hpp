

#ifndef MIPS_ASSEMBLER_HPP
#define MIPS_ASSEMBLER_HPP

#include <sstream>
#include <stdint.h>
#include <string>
#define R_num 18
#define I_num 11
#define J_num 3

class MIPS_Assembler {
private:
  enum Type { R, I, J };

  static const unsigned int Registers_num = 32;
  static const unsigned int Bit_size = 32;
  static const unsigned int Max_26 = 0x3FFFFFF;
  static const unsigned int Max_16 = 0xFFFF;

  static const Type getTypeAndIndex(const std::string &instr, unsigned int &j) {

    if (instr == "add") {
      j = 0;
      return Type::R;
    } else if (instr == "addu") {
      j = 1;
      return Type::R;
    } else if (instr == "and") {
      j = 2;
      return Type::R;
    }
    if (instr == "jr") {
      j = 3;
      return Type::R;
    } else if (instr == "nor") {
      j = 4;
      return Type::R;
    } else if (instr == "or") {
      j = 5;
      return Type::R;
    } else if (instr == "sll") {
      j = 6;
      return Type::R;
    } else if (instr == "sllv") {
      j = 7;
      return Type::R;
    } else if (instr == "slt") {
      j = 8;
      return Type::R;
    } else if (instr == "sltu") {
      j = 9;
      return Type::R;
    } else if (instr == "sra") {
      j = 10;
      return Type::R;
    } else if (instr == "srav") {
      j = 11;
      return Type::R;
    } else if (instr == "srl") {
      j = 12;
      return Type::R;
    } else if (instr == "srlv") {
      j = 13;
      return Type::R;
    } else if (instr == "sub") {
      j = 14;
      return Type::R;
    } else if (instr == "subu") {
      j = 15;
      return Type::R;
    } else if (instr == "xor") {
      j = 16;
      return Type::R;
    }

    if (instr == "addi") {
      j = 0;
      return Type::I;
    } else if (instr == "addiu") {
      j = 1;
      return Type::I;
    } else if (instr == "andi") {
      j = 2;
      return Type::I;
    }
    if (instr == "beq") {
      j = 3;
      return Type::I;
    } else if (instr == "bne") {
      j = 4;
      return Type::I;
    } else if (instr == "lw") {
      j = 5;
      return Type::I;
    } else if (instr == "lui") {
      j = 6;
      return Type::I;
    } else if (instr == "ori") {
      j = 7;
      return Type::I;
    } else if (instr == "slti") {
      j = 8;
      return Type::I;
    } else if (instr == "sw") {
      j = 9;
      return Type::I;
    } else if (instr == "xori") {
      j = 10;
      return Type::I;
    }

    if (instr == "j") {
      j = 0;
      return Type::J;
    } else if (instr == "jpr") {
      j = 1;
      return Type::J;
    } else if (instr == "rpr") {
      j = 2;
      return Type::J;
    }

    throw std::invalid_argument("Unsupported or invalid instruction");
  }

  static void getNextInput(std::stringstream &e, uint32_t &input) {
    throwIfEmpty(e);
    int buffer;
    e >> buffer;
    input = buffer;
  }

  static void throwIfNotEmpty(const std::stringstream &e) {
    if (e.rdbuf()->in_avail())
      throw std::invalid_argument("Invalid syntax");
  }
  static void throwIfEmpty(const std::stringstream &e) {
    if (!e.rdbuf()->in_avail())
      throw std::invalid_argument("Invalid syntax");
  }

  static void checkBounds(const uint32_t number, const uint32_t limit,
                          const std::string &s) {
    if (number > limit)
      throw std::invalid_argument(s + " out of bounds");
  }

public:
  // Translates a MIPS true instruction to its equivalent machine code. Throws
  // an std::invalid_argument exception if instruction is invalid or
  // unsupported.
  static uint32_t exprToMachine(const std::string &expression) {
    std::stringstream e(expression);
    std::string instr;
    e >> instr;

    uint32_t machine_code, opcode, funct, rd, rt, rs, shamt, immi_16, immi_26;
    machine_code = opcode = funct = rd = rt = rs = shamt = immi_16 = immi_26 =
        0x0;

    unsigned int j = INT_MAX;

    switch (getTypeAndIndex(instr, j)) {
    case Type::R: // NOTE: check if added (or removed) any R instructions
      switch (j) {
      case 0:
        funct = 0x20;
        break;
      case 1:
        funct = 0x21;
        break;
      case 2:
        funct = 0x24;
        break;
      case 3:
        funct = 0x8;
        break;
      case 4:
        funct = 0x27;
        break;
      case 5:
        funct = 0x25;
        break;
      case 6:
        funct = 0x0;
        break;
      case 7:
        funct = 0x4;
        break;
      case 8:
        funct = 0x2A;
        break;
      case 9:
        funct = 0x2B;
        break;
      case 10:
        funct = 0x3;
        break;
      case 11:
        funct = 0x7;
        break;
      case 12:
        funct = 0x2;
        break;
      case 13:
        funct = 0x6;
        break;
      case 14:
        funct = 0x22;
        break;
      case 15:
        funct = 0x23;
        break;
      case 16:
        funct = 0x26;
        break;
      case 17:
        funct = 0x1B;
        break;
      }
      getNextInput(e, rd);
      switch (j) {
      case 17: // rpr
      case 3:  // jr
        rs = rd;
        rd = 0;
        break;
      case 6:  // sll
      case 10: // sra
      case 12: // srl
        getNextInput(e, rt);
        getNextInput(e, shamt);
        break;
      case 7:  // sllv
      case 11: // srav
      case 13: // srlv
        getNextInput(e, rt);
        getNextInput(e, rs);
        break;
      default: // add addu and nor or slt sltu sub subu xor
        getNextInput(e, rs);
        getNextInput(e, rt);
      }
      break;

    case Type::I: // NOTE: check if added (or removed) any I instructions
      switch (j) {
      case 0:
        opcode = 0x8;
        break;
      case 1:
        opcode = 0x9;
        break;
      case 2:
        opcode = 0xC;
        break;
      case 3:
        opcode = 0x4;
        break;
      case 4:
        opcode = 0x5;
        break;
      case 5:
        opcode = 0x23;
        break;
      case 6:
        opcode = 0xF;
        break;
      case 7:
        opcode = 0xD;
        break;
      case 8:
        opcode = 0xA;
        break;
      case 9:
        opcode = 0x2B;
        break;
      case 10:
        opcode = 0xE;
        break;
      }

      getNextInput(e, rt);
      switch (j) {
      case 6: // lui
        getNextInput(e, immi_16);
        break;
      case 5: // lw
      case 9: // sw
        getNextInput(e, immi_16);
        getNextInput(e, rs);
        break;
      default: // addi addiu andi beq bne ori slti xori
        getNextInput(e, rs);
        getNextInput(e, immi_16);
      }
      break;

    case Type::J: // NOTE: check if added (or removed) any J instructions
      switch (j) {
      case 0:
        opcode = 0x2;
        break;
      case 1:
        opcode = 0x3;
        break;
      case 2:
        opcode = 0x1C;
        break;
      }
      if (j < 2)
        getNextInput(e, immi_26);
      break;
    }

    checkBounds(rd, Registers_num - 1, "Destination register");
    checkBounds(rt, Registers_num - 1, "Target register");
    checkBounds(rs, Registers_num - 1, "Source register");
    checkBounds(shamt, Bit_size - 1, "Shift amount");
    // checkBounds(immi_26, Max_26, "Jump target");
    // checkBounds(immi_16, Max_16, "Immediate");

    throwIfNotEmpty(e);

    immi_16 &= Max_16;
    immi_26 &= Max_26;

    opcode <<= 26;
    rs <<= 21;
    rt <<= 16;
    rd <<= 11;
    shamt <<= 6;

    machine_code = opcode | rs | rt | rd | shamt | funct | immi_16 | immi_26;

    return machine_code;
  }
};

#endif

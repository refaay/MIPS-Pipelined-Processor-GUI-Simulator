

#ifndef MIPS_Control_Unit_hpp
#define MIPS_Control_Unit_hpp

#include "Macros.h"
#include <stdint.h>
class MIPS_Control_Unit {
public:
  static void getControlSignals(uint32_t OPCODE, uint32_t function,
                                uint32_t &MemToReg, uint32_t &MemWrite,
                                uint32_t &ALUSrc, uint32_t &RegDst,
                                uint32_t &RegWrite, uint32_t &Branch,
                                uint32_t &Branch_on_equal, uint32_t &Jump,
                                uint32_t &Link_on_Jumping,
                                uint32_t &Stack_Jumping, uint32_t &ALUcontrol) {

    switch (OPCODE) {
    case R_OPCODE:
      switch (function) {
      case ADD_FUNC:
      case ADDU_FUNC:
        ALUcontrol = ADD;
        break;
      case SUB_FUNC:
      case SUBU_FUNC:
        ALUcontrol = SUB;
        break;
      case AND_FUNC:
        ALUcontrol = AND;
        break;
      case NOR_FUNC:
        ALUcontrol = NOR;
        break;
      case OR_FUNC:
        ALUcontrol = OR;
        break;
      case SLL_FUNC:
        ALUcontrol = SLL;
        break;
      case SLLV_FUNC:
        ALUcontrol = SLLV;
        break;
      case SLT_FUNC:
      case SLTU_FUNC:
        ALUcontrol = SLT;
        break;
      case SRA_FUNC:
        ALUcontrol = SRA;
        break;
      case SRAV_FUNC:
        ALUcontrol = SRAV;
        break;
      case SRL_FUNC:
        ALUcontrol = SRL;
        break;
      case SRLV_FUNC:
        ALUcontrol = SRLV;
        break;
      case XOR_FUNC:
        ALUcontrol = XOR;
        break;
      case JR_FUNC:
      case RPR_FUNC:
        ALUcontrol = ADD;
        break;
      }
      RegWrite = RegDst = true;
      ALUSrc = Branch = MemWrite = MemToReg = Jump = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case LW_OP:
      ALUcontrol = ADD;
      RegWrite = ALUSrc = MemToReg = true;
      RegDst = Branch = MemWrite = Jump = Branch_on_equal = Link_on_Jumping =
          Stack_Jumping = false;
      break;

    case SW_OP:
      ALUcontrol = ADD;
      ALUSrc = MemWrite = true;
      RegWrite = RegDst = Branch = Jump = MemToReg = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case BEQ_OP:
      ALUcontrol = SUB;
      Branch = Branch_on_equal = true;
      RegWrite = RegDst = ALUSrc = MemWrite = MemToReg = Jump =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case BNE_OP:
      ALUcontrol = SUB;
      Branch = true;
      RegWrite = RegDst = Branch_on_equal = ALUSrc = MemWrite = MemToReg =
          Jump = Link_on_Jumping = Stack_Jumping = false;
      break;

    case ADDI_OP:
    case ADDIU_OP:
      ALUcontrol = ADD;
      RegWrite = ALUSrc = true;
      RegDst = Branch = MemWrite = MemToReg = Jump = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case ANDI_OP:
      ALUcontrol = AND;
      RegWrite = ALUSrc = true;
      RegDst = Branch = MemWrite = MemToReg = Jump = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case ORI_OP:
      ALUcontrol = OR;
      RegWrite = ALUSrc = true;
      RegDst = Branch = MemWrite = MemToReg = Jump = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case XORI_OP:
      ALUcontrol = XOR;
      RegWrite = ALUSrc = true;
      RegDst = Branch = MemWrite = MemToReg = Jump = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case SLTI_OP:
      ALUcontrol = SLT;
      RegWrite = ALUSrc = true;
      RegDst = Branch = MemWrite = MemToReg = Jump = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case LUI_OP:
      ALUcontrol = LUI;
      RegWrite = ALUSrc = true;
      RegDst = Branch = MemWrite = MemToReg = Jump = Branch_on_equal =
          Link_on_Jumping = Stack_Jumping = false;
      break;

    case J_OP:
      ALUcontrol = ADD;
      Jump = true;
      RegDst = Branch = MemWrite = MemToReg = Branch_on_equal = RegWrite =
          ALUSrc = Link_on_Jumping = Stack_Jumping = false;
      break;

    case JAL_OP:
      ALUcontrol = ADD;
      Jump = Link_on_Jumping = true;
      RegDst = Branch = MemWrite = MemToReg = RegWrite = ALUSrc =
          Stack_Jumping = false;
      break;

    case JPR_OP:
      ALUcontrol = ADD;
      Jump = Stack_Jumping = true;
      RegDst = Branch = MemWrite = MemToReg = RegWrite = ALUSrc =
          Link_on_Jumping = false;
      break;
    }
  }
  // static uint32_t getControlSignals(uint32_t OPCODE, uint32_t function);
};

#endif /* MIPS_Control_Unit_hpp */

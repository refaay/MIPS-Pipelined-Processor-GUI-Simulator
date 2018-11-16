

#ifndef ALU_H
#define ALU_H

#include "Macros.h"
#include <stdint.h>
class ALU {
public:
  static void ALUResult(uint32_t a, uint32_t b, uint32_t function,
                        uint32_t shamout, uint32_t &result, bool &zeroflag) {
    ALUResult(a, b, function, shamout, result);
    zeroflag = result == 0;
  }
  static void ALUResult(uint32_t a, uint32_t b, uint32_t function,
                        uint32_t shamout, uint32_t &result) {
    switch (function) {
    case ADD:
      result = a + b;
      break;
    case SUB:
      result = a - b;
      break;
    case AND:
      result = a & b;
      break;
    case OR:
      result = a | b;
      break;
    case XOR:
      result = a ^ b;
      break;
    case SLL:
      result = signed(b) << (shamout & 0x1F);
      break;
    case SRL:
      result = unsigned(b) >> (shamout & 0x1F);
      break;
    case SRA:
      result = signed(b) >> (shamout & 0x1F);
      break;
    case SLT:
      result = signed(a) < signed(b);
      break;
    case NOR:
      result = ~(a | b);
      break;
    case SLLV:
      result = signed(b) << (a & 0x1F);
      break;
    case SRLV:
      result = unsigned(b) >> (a & 0x1F);
      break;
    case SRAV:
      result = signed(b) >> (a & 0x1F);
      break;
    case LUI:
      result = unsigned(b) << 16;
    }
  }
};

#endif /* ALU_hpp */


#ifndef MIPS_Decoder_hpp
#define MIPS_Decoder_hpp

#include <stdint.h>

class MIPS_Decoder {
public:
  static void decodeInstruction(uint32_t instruction, uint32_t &OpCode,
                                uint32_t &function, uint32_t &RS, uint32_t &RT,
                                uint32_t &RD, uint32_t &immi_ext) {
    immi_ext = (instruction & 0xFFFF);
    immi_ext |= ((instruction >> 15) & 1) ? 0xFFFF0000 : 0x0;
    RS = (instruction >> 21) & 0x1F;
    RT = (instruction >> 16) & 0x1F;
    RD = (instruction >> 11) & 0x1F;
    function = instruction & 0x3F;
    OpCode = (instruction >> 26) & 0x3F;
  }
};
#endif /* MIPS_Decoder_hpp */

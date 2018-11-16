
#ifndef MIPS_R4000_Forwarding_Unit_hpp
#define MIPS_R4000_Forwarding_Unit_hpp

#include <stdint.h>

class MIPS_R4000_Forwarding_Unit {
public:
  enum Final_Source { EX, DF, DS, TC_mem, TC_alu };

  static Final_Source getDecision(uint32_t rs_EX, uint32_t rd_DF,
                                  bool reg_we_DF, uint32_t rd_DS,
                                  bool reg_we_DS, uint32_t rd_TC,
                                  bool reg_we_TC, uint32_t rt_TC,
                                  bool mem_to_reg_TC) {

    if (rs_EX == 0)
      return Final_Source::EX;

    if (reg_we_DF && rs_EX == rd_DF)
      return Final_Source::DF;

    if (reg_we_DS && rs_EX == rd_DS)
      return Final_Source::DS;

    if (reg_we_TC && mem_to_reg_TC && rs_EX == rt_TC)
      return Final_Source::TC_mem;

    if (reg_we_TC && rs_EX == rd_TC)
      return Final_Source::TC_alu;

    return Final_Source::EX;
  }
};

#endif /* MIPS_R4000_Forwarding_Unit_hpp */

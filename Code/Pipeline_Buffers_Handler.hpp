
#ifndef Pipeline_Buffers_Handler_hpp
#define Pipeline_Buffers_Handler_hpp

#include "Register.hpp"
#include <stdint.h>
#include <vector>

class Pipeline_Buffers_Handler {
public:
  struct Register_Logic {
    std::vector<uint32_t> input;
    std::vector<uint32_t> output;
    Register buffer;
  };

  static void
  assignInputBuffers(std::vector<Register_Logic> &Pipelined_Registers, int s,
                     int e) {
    for (int i = s; i <= e; i++)
      Pipelined_Registers[i].buffer.setD(Pipelined_Registers[i].input);
  }
  static void resetBuffers(std::vector<Register_Logic> &Pipelined_Registers,
                           int s, int e, bool should_reset) {
    for (int i = s; i <= e; i++)
      Pipelined_Registers[i].buffer.setReset(should_reset);
  }
  static void enableBuffers(std::vector<Register_Logic> &Pipelined_Registers,
                            int s, int e, bool should_enable) {
    for (int i = s; i <= e; i++)
      Pipelined_Registers[i].buffer.setEnable(should_enable);
  }
  static void updateBuffers(std::vector<Register_Logic> &Pipelined_Registers,
                            int s, int e) {
    for (int i = s; i <= e; i++)
      Pipelined_Registers[i].buffer.update();
  }
  static void readDataBuffers(std::vector<Register_Logic> &Pipelined_Registers,
                              int s, int e) {
    for (int i = s; i <= e; i++)
      Pipelined_Registers[i].buffer.getQ(Pipelined_Registers[i].output);
  }
  static void resizeBuffers(std::vector<Register_Logic> &Pipelined_Registers,
                            int s, int e, int size) {
    for (int i = s; i <= e; i++) {
      Pipelined_Registers[i].input.resize(size);
      Pipelined_Registers[i].output.resize(size);
    }
  }

  static void copyForward(Register_Logic &to, Register_Logic &from) {
    for (int i = 0; i < from.output.size() && i < to.input.size(); i++)
      to.input[i] = from.output[i];
  }
};

#endif /* Pipeline_Buffers_Handler_hpp */

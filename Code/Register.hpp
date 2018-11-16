

#ifndef Register_hpp
#define Register_hpp

#include <stdint.h>
#include <vector>

class Register {
private:
  std::vector<uint32_t> Data, Next_Data;
  bool R, E;

public:
  Register() {
    Data.resize(0);
    Next_Data.resize(0);
    R = E = false;
  }
  Register(int);
  Register(const Register &other)
      : Data(other.Data), Next_Data(other.Next_Data), R(other.R), E(other.E) {}
  Register(Register &&other)
      : Data(other.Data), Next_Data(other.Next_Data), R(other.R), E(other.E) {}

  ~Register() {}

  void resize(int);

  void setD(const std::vector<uint32_t> &d) { Next_Data = d; }
  void getQ(std::vector<uint32_t> &Q) { Q = Data; }

  void setReset(bool reset) { R = reset; }
  void setEnable(bool enable) { E = enable; }

  void update() {
    if (R)
      for (int i = 0; i < Data.size(); i++)
        Data[i] = 0;
    else if (E)
      Data = Next_Data;
  }
};

#endif /* Register_hpp */

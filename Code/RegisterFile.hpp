

#ifndef RegisterFile_hpp
#define RegisterFile_hpp

#include <stdexcept>
#include <stdint.h>
#include <vector>

class RegisterFile {
public:
  RegisterFile() { array.resize(0); }
  RegisterFile(uint32_t size) {
    array.resize(size);
    for (int i = 0; i < array.size(); i++)
      array[i] = 0;
  }
  RegisterFile(const RegisterFile &other) : array(other.array) {}

  ~RegisterFile() {}

  void resizeAndReset(uint32_t size) {
    array.resize(size);
    for (int i = 0; i < array.size(); i++)
      array[i] = 0;
  }
  void write(uint32_t index, uint32_t value, bool RegWrite) {
    if (RegWrite && index != 0 && index < array.size())
      array[index] = value;
  }
  uint32_t read(uint32_t index) {
    if (index < array.size())
      return array[index];
    else
      return 0;
  }
  std::vector<uint32_t> array;

private:
};
#endif /* RegisterFile_hpp */

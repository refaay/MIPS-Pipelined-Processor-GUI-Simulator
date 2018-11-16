

#ifndef Memory_hpp
#define Memory_hpp

#include <stdint.h>
#include <vector>

using namespace std;

class Memory {
public:
  Memory() { mem_array.resize(0); }
  Memory(uint32_t size) { mem_array.resize(size); }
  void resize(uint32_t size) { mem_array.resize(size); }
  uint32_t read(uint32_t index) {
    if (index < mem_array.size())
      return mem_array[index];
    else
      return 0;
  }
  bool insert(uint32_t index, uint32_t data, bool enable) {
    if (index < mem_array.size() && enable) {
      mem_array[index] = data;
      return true;
    } else
      return false;
  }
  bool insert(uint32_t data, bool enable) {
    if (enable) {
      mem_array.push_back(data);
      return true;
    } else
      return false;
  }
  vector<uint32_t> mem_array;

private:
};

#endif /* Memory_hpp */



#ifndef Jump_Table_hpp
#define Jump_Table_hpp

#include <stdint.h>
#include <vector>

class Jump_Table {

private:
  struct line {
    uint32_t from_address;
    uint32_t target_address;
  };

  std::vector<line> Table;

public:
  Jump_Table() { Table.resize(0); }
  Jump_Table(const Jump_Table &other) : Table(other.Table) {}
  Jump_Table(Jump_Table &&other) : Table(other.Table) {}

  ~Jump_Table() {}

  // Adds a new branch instruction, via its original pc and target pc, to the
  // table.
  void addIfNotPresent(uint32_t pc, uint32_t target_pc) {
    if (!exists(pc)) {
      line l;
      l.from_address = pc;
      l.target_address = target_pc;
      Table.push_back(l);
    }
  }
  // Gets the target pc
  uint32_t getSpeculatedAddress(uint32_t pc) const {
    for (int i = 0; i < Table.size(); i++)
      if (Table[i].from_address == pc)
        return Table[i].target_address;
    return pc;
  }
  // Checks if this instruction is an identified branch instruction that exists
  // in the table.
  bool exists(uint32_t pc) const {
    for (int i = 0; i < Table.size(); ++i)
      if (pc == Table[i].from_address)
        return true;
    return false;
  }
  // Clears the table
  void clear() { Table.resize(0); }
};

#endif /* Jump_Table_hpp */

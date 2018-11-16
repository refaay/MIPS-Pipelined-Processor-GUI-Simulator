

#ifndef Branch_Predictor_hpp
#define Branch_Predictor_hpp

#include <stdint.h>
#include <vector>

class Branch_Predictor {
public:
  enum Decision { Definitely_NO, NO, YES, Definitely_YES };

  Branch_Predictor() { Table.resize(0); }
  Branch_Predictor(const Branch_Predictor &other) : Table(other.Table) {}

  Branch_Predictor(Branch_Predictor &&other) : Table(other.Table) {}

  ~Branch_Predictor() {}
  // Adds a new branch instruction, via its original pc and target pc, to the
  // table.
  void addIfNotPresent(uint32_t pc, uint32_t target_pc) {
    if (!exists(pc)) {
      line l;
      l.from_address = pc;
      l.target_address = target_pc;
      l.decision = Decision::Definitely_NO;
      Table.push_back(l);
    }
  }

  // Gets a branch decision based on current state.
  bool shouldBranch(uint32_t pc) const {
    for (int i = 0; i < Table.size(); ++i)
      if (pc == Table[i].from_address)
        return (Table[i].decision >> 1);
    return false;
  }

  // Gets the target pc
  uint32_t getSpeculatedAddress(uint32_t pc) const {
    for (int i = 0; i < Table.size(); i++) {
      if (Table[i].from_address == pc) {
        if (int(Table[i].decision) >> 1)
          return Table[i].target_address;
        else
          return pc;
      }
    }
    return pc;
  }
  // Gets a detailed branch decision based on current state.
  Decision getDecision(uint32_t pc) const {
    for (int i = 0; i < Table.size(); ++i)
      if (pc == Table[i].from_address)
        return Table[i].decision;
    return Decision::Definitely_NO;
  }
  // Updates the branch decision based on new information
  bool updateDecision(uint32_t pc, bool taken) {
    for (int i = 0; i < Table.size(); i++)
      if (pc == Table[i].from_address) {
        if (taken && Table[i].decision != Decision::Definitely_YES) {
          Table[i].decision = Decision(int(Table[i].decision) + 1);
          return true;
        }
        if (!taken && Table[i].decision != Decision::Definitely_NO) {
          Table[i].decision = Decision(int(Table[i].decision) - 1);
          return true;
        }
      }
    return false;
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

  // returns a specific line
  bool access(int index, uint32_t &from, uint32_t &target, int &state) {
    if (index < 0 || index >= Table.size()) {
      from = target = state = 0;
      return 0;
    } else {
      from = Table[index].from_address;
      target = Table[index].target_address;
      state = int(Table[index].decision);
      return 1;
    }
  }

private:
  struct line {
    uint32_t from_address;
    uint32_t target_address;
    Decision decision;
  };

  std::vector<line> Table;
};

#endif /* Branch_Predictor_hpp */

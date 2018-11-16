
#ifndef PSEUDOCONVERTER_HPP
#define PSEUDOCONVERTER_HPP
#include <string>
#include <vector>

using namespace std;

class PSEUDOCONVERTER {

public:
  static void convert_to_true(vector<string> &x) {
    string D(""), S1(""), S2("");
    for (int i = 0; i < x.size(); i++) {
      if (x[i].find("blt") == 0) {
        x[i].erase(0, x[i].find(" ") + 1);
        D = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S1 = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S2 = x[i].substr(0, x[i].length());

        x[i] = "slt 1 " + D + " " + S1;
        x.insert(x.begin() + i + 1, "bne 1 0 " + S2);
      }
      if (x[i].find("bgt") == 0) {
        x[i].erase(0, x[i].find(" ") + 1);
        D = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S1 = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S2 = x[i].substr(0, x[i].length());

        x[i] = "slt 1 " + S1 + " " + D;
        x.insert(x.begin() + i + 1, "bne 1 0 " + S2);
      }
      if (x[i].find("ble") == 0) // ble $rt, $rs, immediate
      {
        x[i].erase(0, x[i].find(" ") + 1);
        D = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S1 = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S2 = x[i].substr(0, x[i].length());

        x[i] = "slt 1 " + S1 + " " + D;
        x.insert(x.begin() + i + 1, "beq 1 0 " + S2);
      }
      if (x[i].find("neg")) {
      }
      if (x[i].find("bge") == 0) {
        x[i].erase(0, x[i].find(" ") + 1);
        D = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S1 = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" ") + 1);
        S2 = x[i].substr(0, x[i].length());

        x[i] = "slt 1 " + D + " " + S1;
        x.insert(x.begin() + i + 1, "beq 1 0 " + S2);
      }
      if (x[i].find("li") == 0) // li 2 200
      {
        x[i].erase(0, x[i].find(" "));
        D = x[i].substr(0, x[i].rfind(" "));
        x[i].erase(0, x[i].rfind(" "));
        S1 = x[i].substr(0, x[i].length());

        x[i] = "addi" + D + " 0" + S1;
      }
      if (x[i].find("la")) {
      }
      if (x[i].find("move") == 0) // move 2 3
      {
        x[i].erase(0, x[i].find(" "));
        D = x[i].substr(0, x[i].find(" "));
        x[i].erase(0, x[i].find(" "));
        S1 = x[i].substr(0, x[i].length());

        x[i] = "addi" + S1 + " 0";
      }
    }
  }
};
#endif /* pseudoconverter_h */

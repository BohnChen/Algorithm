/**
 * leetcode : 860
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-06-01 22:08
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int five = 0, ten = 0, twenty = 0;
    for (int bill : bills) {
      if (bill == 5) {
        ++five;
      } else if (bill == 10) {
        if (five < 1)
          return false;
        ++ten;
        --five;
      } else {
        if (five > 0 && ten > 0) {
          --five;
          --ten;
        } else if (five >= 3) {
          five -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> bills{5, 5, 5, 10, 20};
  if (s.lemonadeChange(bills))
    std::cout << "true" << std::endl;
  else
    std::cout << "false" << std::endl;
  return 0;
}

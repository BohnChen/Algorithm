/**
 * leetcode : 134
 * Descrip	 : Need to be reviewed, today is too late.
 * Paragra  : Bohn Chen 2022-05-30 22:59
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
      curSum += gas[i] - cost[i];
      totalSum += gas[i] - cost[i];
      if (curSum < 0) {
        start = i + 1;
        curSum = 0;
      }
    }
    if (totalSum < 0)
      return -1;
    return start;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  // [1,2,3,4,5]
  // [3,4,5,1,2]
  vector<int> gas{1, 2, 3, 4, 5};
  vector<int> cost{3, 4, 5, 1, 2};
  int i = s.canCompleteCircuit(gas, cost);
  if (i != -1)
    std::cout << "OK!" << std::endl;
  else
    std::cout << "No, You can't." << std::endl;
  return 0;
}

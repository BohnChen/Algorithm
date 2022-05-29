/**
 * leetcode : 45
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-05-29 22:10
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int curDistance = 0;  // 可以到达的最远下标
    int nextDistance = 0; // 下一步可以到达的最远下标
    int res = 0;          // 存放结果
    for (int i = 0; i < nums.size() - 1; ++i) {
      // get the distantest index everytime
      nextDistance = max(i + nums[i], nextDistance);
      // we should jump again when get the current distantest index.
      if (i == curDistance) {
        ++res;
        curDistance = nextDistance;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{2, 3, 1, 1, 4};
  if (s.jump(nums) > 0)
    std::cout << "^V^, We jump " << s.jump(nums) << " steps to get to the end."
              << std::endl;
  else
    std::cout << "T-T, We can not get to the end. " << std::endl;
  return 0;
}

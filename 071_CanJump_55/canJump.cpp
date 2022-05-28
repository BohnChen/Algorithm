/**
 * leetcode : 55
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-05-28 22:14
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool canJump(vector<int> &nums) {
    // cover is the max index
    int cover = 0;
    if (nums.size() == 1)
      return true;
    for (int i = 0; i <= cover; ++i) {
      // Update the max steps we can go every time. And this is points very
      // much.
      cover = max(i + nums[i], cover);
      if (cover >= nums.size() - 1)
        return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{2, 3, 1, 1, 4};
  if (s.canJump(nums))
    std::cout << "^v^ , We can get the end of nums!" << std::endl;
  else
    std::cout << "T-T , We can not get the end of nums!" << std::endl;
  return 0;
}

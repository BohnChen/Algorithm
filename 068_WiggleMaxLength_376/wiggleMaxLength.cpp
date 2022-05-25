/**
 * leetcode : 376
 * Descrip	 : Transfer the problem to count the sum of head and bottom of a
 * wave.
 * Paragra  : Bohn Chen 2022-05-25 21:42
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // get the head and the bottom of the wave.
  // The wave is consist with the number in vector.
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums.size();
    int curDiff = 0; // current difference.
    int preDiff = 0; // previous difference.
    int result = 1;  // The minimal size is 1 when at the end.
    for (int i = 0; i < nums.size() - 1; ++i) {
      curDiff = nums[i + 1] - nums[i];
      // get a suitable difference.
      if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
        ++result;
        preDiff = curDiff;
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{1, 7, 4, 9, 2, 5};
  std::cout << "The result is " << s.wiggleMaxLength(nums) << std::endl;
  return 0;
}

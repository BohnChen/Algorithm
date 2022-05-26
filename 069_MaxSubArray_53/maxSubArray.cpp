/**
 * leetcode : 53
 * Descrip	 : If current one below 0, the sum should begin from here.
 * Paragra  : Bohn Chen 2022-05-26 22:36
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int result = INT32_MIN;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      count += nums[i];
      // Get the max one every time
      if (count > result) {
        result = count;
      }
      // Sum less than before if the current element under 0.
      if (count <= 0)
        count = 0;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << "The result is " << s.maxSubArray(nums) << std::endl;
  return 0;
}

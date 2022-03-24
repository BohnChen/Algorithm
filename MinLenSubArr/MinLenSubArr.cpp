/**
 * leetcode : 209
 * Bohn Chen 2022-03-24 23:03
 */
#include <iostream>
#include <vector>


class Solution {
	public:
		int minSubArrayLen(int target, std::vector<int> nums) {
			int i = 0;											// Start Index of Slide window
			int SubLen = 0;									// The length of the slide window
			int sum = 0;										// Sum of all elements in slide window
			int result = INT32_MAX ;		// return value
			for (int j = 0; j < nums.size(); ++j) {
				sum += nums[j];
				while (sum >= target) {
					SubLen = j - i + 1;
					result = result < SubLen ? result : SubLen;
					sum -= nums[i++];				// Change start position
				}
			}
			return result == INT32_MAX ? 0 : result;
		}
};

int main(int argc, char *argv[])
{
	std::vector<int> vec { 12, 28, 83, 4, 25,26, 25, 2, 25, 25, 25, 12 };
	Solution s;
	std::cout << "Res : " <<  s.minSubArrayLen(213, vec) << std::endl; // it should be 8

	return 0;
}

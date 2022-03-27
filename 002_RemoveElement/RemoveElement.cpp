/**
 * leetcode : 27
 * Remove Element.
 * Bohn Chen 2022-03-23 22:56
 */
#include <vector>
#include <iostream>


// time complexity: O(n)
// space complexity: O(1)
class Solution {
	// slow and fast Index 
	// This method can slove many problems in array and linklist.
	public:
		int RemoveElement(std::vector<int> &nums, int val ) {
			int slowIndex = 0;
			for(int fastIndex = slowIndex; fastIndex < nums.size(); ++fastIndex) {
				if (val != nums[fastIndex]) 
					nums[slowIndex++] = nums[fastIndex];
			}
			return slowIndex;
		}
		void print(std::vector<int> nums, int len) {
			for (int i = 0; i < len; ++i) {
				std::cout << " " << nums[i];
			}
		}
};


int main(int argc, char *argv[])
{
	Solution s;
	std::vector<int> vec {1, 2, 3, 4, 2, 2, 2};
	s.print(vec, vec.size());
	std::cout << std::endl;
	int k = s.RemoveElement(vec, 2);
	s.print(vec, k);
	return 0;
}

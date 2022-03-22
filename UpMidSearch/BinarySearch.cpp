/**
 * leetcode : 704
 * nowcoder : BM17
 * Bohn Chen 2022-03-22 22:19
 */
#include <vector>
#include <iostream>

// mid needs to be changed with left and right.
class Solution {
	public: 
		// [left, right]
		int search (std::vector<int> &nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			// when left == right , the index is legal, so we use ">=" here.
			while (left <= right) {
				// "+" has higher precedence than ">>".
				int mid = left + ((right - left) >> 1);
				if (nums[mid] == target)
					return mid;
				else if (nums[mid] < target) 
					// left is still included in searching range.
					left = mid + 1;
				else
					// right is still included in searching range.
					right = mid - 1;
			}
			return -1;
		}

		// [left, right)
		int search2 (std::vector<int> &nums, int target) {
			int left = 0;
			int right = nums.size(); // Now right is unlegal.
			// when left == right , the index is legal, so we use "<" here.
			while (left < right) {
				// "+" has higher precedence than ">>".
				int mid = left + ((right - left) >> 1);
				if (nums[mid] == target)
					return mid;
				else if (nums[mid] < target) 
					// left is still included in searching range.
					left = mid + 1;
				else
					// right is still not included in searching range.
					right = mid;
			}
			return -1;
		}

};


int main(int argc, char *argv[])
{
	// vec is a sorted vec.
	std::vector<int> vec {1, 4, 45, 54, 65, 1232};
	Solution s;
	int ret = s.search(vec, 5);
	std::cout << "ret : " << ret << std::endl;

	return 0;
}

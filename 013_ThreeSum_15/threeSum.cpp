/**
 * today, we also introduce two methods to slove this problem,And differetly, we will use some tricks here.
 * leetcode : 15
 * Bohn Chen 2022-04-03 20:37
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
	// hash : Not a recommanded one
	vector<vector<int>> threeSum(vector<int>& nums) {
		// first method using hash, but not a effective one
		if(nums.size() < 3) 
			return {  };
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if(nums[0] == 0 && nums[0] == nums[nums.size() - 1])
			return {{0, 0, 0}};
		for(int i = 0; i < nums.size(); ++i) {
			// make sure that the first element is special;
			if(i > 0 && nums[i] == nums[i - 1])
				continue;
			unordered_set<int> mySet;
			for(int j = i + 1; j < nums.size(); ++j) {
				// make sure that the second element is special
				if(j > i + 2 && nums[ j ] == nums[j - 1] && nums[j - 1] == nums[j - 2])
					continue;
				int c = 0 - nums[i] - nums[j];
				if(mySet.find(c) != mySet.end(0)) {
					res.push_back({nums[i], nums[j], c});
					// Make sure that the third element is special
					mySet.erase(c);
				} else {
					mySet.insert(nums[j]);
				}
			}
		}
		return res;
	}


	// two pointers method
	vector<vector<int>> threeSum2(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		// trick 1 : 
		// Handle illegal examples
		if(size < 3 || nums[0] > 0 || nums[size - 1] < 0) 
			return {  };
		if(nums[0] == nums[size - 1] && nums[0] == 0)
			return {{0, 0, 0}};
		// trick 2:
		// get space firstly
		res.reserve(size > 256 ? size : 256);
		for(int i = 0; i < size; ++i) {
			// Make sure that the first element is special
			if(i > 0 && nums[i] == nums[i - 1])
				continue;
			// tricks 3 :
			// if the current minimal value is bigger than 0, break;
			if(nums[i] > 0)
				break;
			int left = i + 1;
			int right = size - 1;
			while(left < right) {
				int target = nums[i] + nums[left] + nums[right];
				if(target > 0) {
					--right;
				} else if (target < 0) {
					++left;
				} else {
					res.push_back({nums[i], nums[left], nums[right]});
					// Make sure the last one element special
					while(left < right && nums[left] == nums[left + 1]) ++left;
					while(left < right && nums[right] == nums[right - 1]) --right;

					++left;
					--right;
				}
			}
		}
		return res;
	}
};



int main(int argc, char *argv[])
{
	Solution s;
	// vector<int> nums { 0, 0, 0, 0, 0, 0, 0 };
	vector<int> nums { 0, 2, 2, 3, 0, 1, 2, 3, -1, -4, 2 };
	for(auto v1 : s.threeSum2(nums)) {
		for (auto v2 : v1) {
			std::cout << v2 << " ";
		}
		std::cout << std::endl;
		
	}
	return 0;
}

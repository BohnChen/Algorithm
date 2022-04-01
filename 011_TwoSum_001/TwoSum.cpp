/**
 * leetcode : 1
 * two sum : the comparision of two different datastructure;
 * Bohn Chen 2022-04-01 21:44
 */
#include <utility>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
	public:
	// Bad method
	vector<int> twoSum1(vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target)
					return { i, j };
			}
		}
		// return a empty array
		// time comlexity : O(n^2);
		return {};
	}
	// Better method
	// time comlexity : O(n);
	vector<int> twoSum2(vector<int>& nums, int target)
	{
		unordered_map<int, int> myMap;
		for (int i = 0; i < nums.size(); ++i) {
			auto iter = myMap.find(target - nums[i]);
			if(iter != myMap.end()) {
				return {iter->second, i};
			}
			// key : nums[i] , value : i
			// myMap.insert(pair<int, int>(nums[i], i));
			myMap.insert(make_pair(nums[i], i));
		}
		return {  };
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums { 2, 7, 11, 15 };
	for(auto c : s.twoSum1(nums, 9))
		std::cout << c << " ";
	return 0;
}

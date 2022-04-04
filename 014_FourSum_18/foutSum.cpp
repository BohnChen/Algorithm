/**
 * four sum : you should handle the value between -10^9 ~ 10^9
 * Bohn Chen 2022-04-04 22:50
 * leetcode : 18
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int size = nums.size();
				// int :  the max value is 2^(32) - 1 : 4000000000 - 1
        long long t = (long long)target;
        long t1 = nums[0];
        long t2 = nums[size - 1];
        if(size < 4 )
            return { };
        for(int i = 0; i < size; ++i) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                int left = j + 1;
                int right = size - 1;

                while(left < right ) {
                    long q1 = nums[i];
                    long q2 = nums[j];
                    long q3 = nums[left];
                    long q4 = nums[right];
                    long long temp = q1 + q2 + q3 + q4;
                    // int temp = nums[i] + nums[j] + nums[left] + nums[right];
                    // cout << temp << " " << endl;    
                    if(t < temp) {
                        --right;
                    } else if (t >temp) {
                        ++left;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) ++left;
                        while(left < right && nums[right] == nums[right - 1]) --right;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};


int main(int argc, char *argv[])
{
	vector<int> nums { 0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000 };
	int target = 1000000000;
	Solution s;
	for(auto c : s.fourSum(nums, target)) {
		for (auto d: c) {
			std::cout << d << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}

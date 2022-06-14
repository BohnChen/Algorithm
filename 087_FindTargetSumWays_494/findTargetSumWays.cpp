/**
* leetcode : 494
* Descrip	 : 背包理论，还是不太懂  
* Paragra  : Bohn Chen 2022-06-14 23:50
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }
        // 此时无解
        if ((target + sum) % 2 == 1) 
        {
            return 0;
        }
        // 此时无解
        if (abs(target) > sum )
        {
            return 0;
        }
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = bagSize; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums { 1, 1, 1, 1, 1 };
	int target = 3;
	std::cout << "There are/is " 
						<< s.findTargetSumWays(nums, target) 
						<< " methods to slove it" 
						<< std::endl;
	return 0;
}


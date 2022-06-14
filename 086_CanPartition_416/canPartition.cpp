/**
* leetcode : 416
* Descrip	 : 背包理论的第一道例题.  
* Paragra  : Bohn Chen 2022-06-13 22:25
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int _nSum  = 0;

        // dp[i] 中的 i 表示背包内元素的总和
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); ++i) 
        {
            _nSum += nums[i];
        }

        // 总和为奇数则必不能分开
        if (_nSum % 2 == 1)
        {
            return false;
        }
        int _nTarget = _nSum / 2;

        // 0-1 背包的逻辑
        for (int _i = 0; _i < nums.size(); ++_i)
        {
            // 每个元素一定不能重复放入背包，所以 for 循环是从大到小遍历的
            for (int _j = _nTarget; _j >= nums[_i]; --_j)
            {
                dp[_j] = max(dp[_j], 
                             dp[_j - nums[_i]] + nums[_i]);
            }
        }

        // 集合总的元素正好可以凑成总和 _nTarget
        if (dp[_nTarget] == _nTarget)
        {
            return true;
        }
        return false;
    }
};
 

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums { 1, 5, 5, 11 };
	if(s.canPartition(nums))
		std::cout << "OK." << std::endl;
	else
		std::cout << "NO." << std::endl;
	return 0;
}


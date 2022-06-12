/**
* leetcode : 96
* Descrip	 : dp[1] = 1 为头结点不同左子树个数 * 1 为头结点不同右子树个数
*									 = dp[0] * dp[0]
*						 dp[2] = 1 为头不同左个数 * 1 为头不同右个数 + 2 为头不同左个数 * 2 为头不同右个数
*									 = dp[0] * dp[1] + dp[1] * dp[0]
*						 dp[3] = 1 为头不同左个数 * 1 为头不同右个数 + 2 为头不同左个数 * 2 为头不同右个数 
*									 + 3 为头不同左个数 * 3 为头不同右个数 
*									 = dp[0] * dp[2] + dp[1] * dp[1] + dp[2] * dp[0]
*						 ……
*						 dp[n]
* Paragra  : Bohn Chen 2022-06-11 22:04
*/
// 2022-06-12 10:30 现在把这道题目想法补上来。
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int numTrees(int n) 
		{
        vector<int> dp(n + 1);
        dp[0] = 1;
				for (int _nCtlTime = 1; _nCtlTime <= n; ++_nCtlTime)
        {
            for (int startIndex = 0, 
                endIndex = _nCtlTime - 1; 
                startIndex < _nCtlTime && endIndex >= 0; 
                ++startIndex, --endIndex)
            {
                dp[_nCtlTime] += dp[startIndex] * dp[endIndex];
						}
				}
				/*
        for (auto _nVal: dp)
        {
            cout << _nVal << " ";
        }
				*/
				// carl 的实现
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= i; ++j) {
        //         dp[i] += dp[j - 1] * dp[i - j];
        //     }
        // }
        return dp[n];
    }
};


int main(int argc, char *argv[])
{
	Solution s;
	int n = 4;
	std::cout << "The result is " << s.numTrees(n) << std::endl;
	return 0;
}

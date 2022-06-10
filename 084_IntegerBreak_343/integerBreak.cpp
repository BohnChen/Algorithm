/**
* leetcode : 343
* Descrip	 : none  
* Paragra  : Bohn Chen 2022-06-10 22:32
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
/*
    int integerBreak(int n) {
        // time complexity : O(n^2)
        // space complexity : O(n)
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) 
        {
            for (int j = 1; j < i - 1; ++j) 
            {
                dp[i] = max({ dp[i], (i = j) * j, dp[i - j] * j} );
            }
        }
        return dp[n];
    }
*/

    // 需要证明合理性的贪心算法
    int integerBreak(int n ) 
    {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int result = 1;
        while (n > 4) 
        {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	std::cout << "The result is " << s.integerBreak(10) << std::endl;
	return 0;
}

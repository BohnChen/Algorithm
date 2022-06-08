/**
* leetcode : 46
* Descrip	 : none  
* Paragra  : Bohn Chen 2022-06-08 22:32
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 深度优先
        // 动态规划 +
        // 数论
        int dp[m][n];
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int i = 0; i < n; ++i) dp[0][i] = 1;
        for (int i = 1; i < m; ++i) 
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	std::cout << "There are " << s.uniquePaths(7, 3) << " pathes to get to the end." << std::endl;
	;
	return 0;
}


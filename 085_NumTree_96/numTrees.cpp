/**
* leetcode : 96
* Descrip	 : none  
* Paragra  : Bohn Chen 2022-06-11 22:04
*/
// 今天有点摸鱼了
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};


int main(int argc, char *argv[])
{
	Solution s;
	int n = 3;
	std::cout << "The result is " << s.numTrees(n) << std::endl;
	return 0;
}

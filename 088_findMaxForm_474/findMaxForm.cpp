/**
* leetcode : 474
* Descrip	 : none  
* Paragra  : Bohn Chen 2022-06-15 23:55
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (string str : strs)
        {
            int oneNum = 0, zeroNum = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    zeroNum++;
                }
                else 
                {
                    oneNum++;
                }
            }
            for (int i = m; i >= zeroNum; --i)
            {
                for (int j = n; j >= oneNum; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> strs { "10","0001","111001","1","0" };
	int n = 3;
	int m = 5;
	std::cout << "The result is " << s.findMaxForm(strs, m, n) << std::endl;
	return 0;
}

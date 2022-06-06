/**
 * leetcode : 70
 * Descrip	 : It is similar with num.509
 * Paragra  : Bohn Chen 2022-06-06 22:29
 */
#include <iostream>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 1)
      return n;
    // Specify the meaning of dp array.
    // dp[i] is the result
    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i <= n; ++i) {
      int sum = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = sum;
    }
    return dp[1];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int n = 3;
  std::cout << "The result is " << s.climbStairs(n) << std::endl;
  return 0;
}

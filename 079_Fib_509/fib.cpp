/**
 * leetcode : 509
 * Descrip	 : The beginning of dynamic programming.
 * Paragra  : Bohn Chen 2022-06-05 22:07
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int fib(int n) {
    if (n <= 1)
      return n;
    // 1. We need only last one and the one before last one.
    // vector<int> dp(n + 1);
    // dp[0] = 0;
    // dp[1] = 1;
    // for(int i = 2; i <= n; ++i) {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // 2. So only two int can do what we want.
    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      int sum = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = sum;
    }
    return dp[1];
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  int n = 4;
  std::cout << "The sum of before " << n << "th one and the last before it is "
            << s.fib(n) << std::endl;
  return 0;
}

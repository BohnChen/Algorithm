/**
 * leetcode : 760
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-06-07 21:56
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> dp(cost.size());
    // 因为我们可以选择第一级还是第二级为起点
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    // for (auto i : dp) {
    //   cout << i << " ";
    // }
    // 最后一步可能不需要话费体力值
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
  }

  int minCostClimbingStairsImprove(vector<int> &cost) {
    // 因为我们可以选择第一级还是第二级为起点
    int dp0 = cost[0];
    int dp1 = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
      int dpi = min(dp0, dp1) + cost[i];
      dp0 = dp1;
      dp1 = dpi;
    }
    // 最后一步可能不需要话费体力值
    return min(dp0, dp1);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  std::cout << "The Min cost is " << s.minCostClimbingStairs(cost) << "."
            << std::endl;
  return 0;
}

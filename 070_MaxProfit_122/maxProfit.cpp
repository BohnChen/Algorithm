/**
 * leetcode : 122
 * Descrip	 : Just collect the positive profit.
 * Paragra  : Bohn Chen 2022-05-27 22:49
 */
// Transformation thought.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Just collect all the positive profit
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
      result += max((prices[i] - prices[i - 1]), 0);
    }
    return result;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  std::cout << "The max profit is " << s.maxProfit(prices) << std::endl;
  return 0;
}

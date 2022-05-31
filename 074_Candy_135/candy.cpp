/**
 * leetcode : 135
 * Descrip	 : Hard one
 * Paragra  : Bohn Chen 2022-05-31 22:48
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> candyVec(ratings.size(), 1);
    // 从前向后遍历
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1])
        candyVec[i] = candyVec[i - 1] + 1;
    }
    // 从后向前遍历
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
      }
    }
    // 统计结果
    int result = 0;
    for (int i = 0; i < candyVec.size(); ++i)
      result += candyVec[i];
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> ratings{1, 0, 2};
  int i = s.candy(ratings);
  std::cout << "The result is " << i << std::endl;
  return 0;
}

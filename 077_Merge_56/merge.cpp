/**
 * leetcode : 56
 * Descrip	 : Lambda
 * Paragra  : Bohn Chen 2022-06-03 09:14
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> result;
    if (intervals.size() == 0)
      return result;
    // 排序的参数使用了 Lambda 表达式
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      if (result.back()[1] >= intervals[i][0]) { // 合并区间
        result.back()[1] = max(result.back()[1], intervals[i][1]);
      } else {
        result.push_back(intervals[i]);
      }
    }
    return result;
  }
};
void printRes(const vector<vector<int>> &res) {
  // std::cout << "[ ";
  for (auto vec : res) {
    std::cout << "[ ";
    for (int i : vec) {
      std::cout << i << " ";
    }
  }
  std::cout << "]";
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> intervals{{1, 4}, {0, 2}, {3, 5}};
  printRes(s.merge(intervals));
  return 0;
}

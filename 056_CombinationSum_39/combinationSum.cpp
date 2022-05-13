/**
 * leetcode : 39
 * Descrip	 : Improve the performance of backtracking by the control
 * condition of for-loop statement Paragra  : Bohn Chen 2022-05-13 21:56
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;

public:
  void backTracking(const vector<int> &candidates, int target, int sum,
                    int startIndex) {
    if (sum > target) {
      return;
    } else if (sum == target) {
      result.push_back(path);
      return;
    }
    // 若把 i = 0 作为条件，这里会有多组顺序不同的重复值
    // for(int i = startIndex; i < candidates.size(); ++i) {
    for (int i = startIndex;
         i < candidates.size() && sum + candidates[i] <= target;
         ++i) { /* 改进 */
      if (sum < target) {
        path.push_back(candidates[i]);
        backTracking(candidates, target, sum + candidates[i], i);
        path.pop_back();
      }
      if (sum > target) {
        path.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    result.clear();
    path.clear();
    // if(candidates.size() < 1)
    //     return {};
    sort(candidates.begin(), candidates.end()); /* 改进 */
    backTracking(candidates, target, 0, 0);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> candidates{2, 3, 5, 7};
  int target = 7;
  std::cout << "[";
  for (auto vec : s.combinationSum(candidates, target)) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
      if (i != vec.size() - 1)
        std::cout << vec[i] << ",";
      else
        std::cout << vec[i];
    }
    std::cout << "]";
  }
  std::cout << "]";
  return 0;
}

/**
 * leetcode : 40
 * Descrip	 : Use a vector<bool> type to keep the resutl unrepeatable
 * Paragra  : Bohn Chen 2022-05-14 23:51
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> path;
  vector<vector<int>> result;
  void backTracking(vector<int> &candidates, int target, int sum, int index,
                    vector<bool> &used) {

    if (sum == target) {
      result.push_back(path);
      return;
    }
    for (int i = index; i < candidates.size() && sum + candidates[i] <= target;
         ++i) {
      // 排除掉同层中的循环
      // 两个相同的值可以被一起使用，但是不同被分开和其他不同的值使用
      // 通过这样避免重复
      if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
        continue;
      }

      path.push_back(candidates[i]);
      used[i] = true;
      backTracking(candidates, target, sum + candidates[i], i + 1, used);
      used[i] = false;
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    result.clear();
    path.clear();
    vector<bool> used(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    backTracking(candidates, target, 0, 0, used);
    return result;
  }
};

int main(int argc, char *argv[]) {
  // [10,1,2,7,6,1,5]
  // 8
  vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
  Solution s;
  int target = 8;
  std::cout << "[";
  for (auto vec : s.combinationSum2(candidates, target)) {
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

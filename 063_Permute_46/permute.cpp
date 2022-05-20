/**
 * leetcode : 47
 * Descrip	 : The first premute problem.
 * Paragra  : Bohn Chen 2022-05-20 22:53
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> path;
  vector<vector<int>> result;
  void backTracking(vector<int> &nums, vector<bool> &used) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i] == true)
        continue;
      path.push_back(nums[i]);
      used[i] = true;
      backTracking(nums, used);
      used[i] = false;
      path.pop_back();
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    path.clear();
    result.clear();
    vector<bool> used(nums.size(), false);
    backTracking(nums, used);
    return result;
  }
};
void printRes(const vector<vector<int>> &res) {
  std::cout << "[ ";
  for (auto vec : res) {
    std::cout << "[ ";
    for (auto i : vec) {
      std::cout << i << " ";
    }
    std::cout << "]";
  }
  std::cout << " ]";
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{1, 2, 3};
  printRes(s.permute(nums));
  return 0;
}

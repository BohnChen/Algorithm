/**
 * leetcode : 47
 * Descrip	 : I begin to comprehend the the method to low dumplication.
 * Paragra  : Bohn Chen 2022-05-21 21:50
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> path;
  vector<vector<int>> result;
  void backTracking(const vector<int> &nums, vector<bool> &used) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      // used[i - 1] == true : 同一枝上重复
      // used[i - 1] == false : 同一层上重复，这时需要跳过
      if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) {
        continue;
      }
      if (used[i] == false) {
        path.push_back(nums[i]);
        used[i] = true;
        backTracking(nums, used);
        used[i] = false;
        path.pop_back();
      }
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
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
  vector<int> nums{1, 1, 2};
  printRes(s.permuteUnique(nums));

  return 0;
}

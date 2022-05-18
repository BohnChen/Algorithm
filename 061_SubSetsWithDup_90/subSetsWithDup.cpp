/**
 * leetcode : 90
 * Descrip	 : a nice using example of used vector.
 * Paragra  : Bohn Chen 2022-05-18 22:13
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;
  void backTracking(vector<int> &nums, int startIndex, vector<bool> &used) {
    result.push_back(path);
    for (int i = startIndex; i < nums.size(); ++i) {
      // used[i - 1] == true:纵向，同一树枝上使用过
      // used[i - 1] == false:横向，同一层上使用过
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }
      path.push_back(nums[i]);
      used[i] = true;
      backTracking(nums, i + 1, used);
      used[i] = false;
      path.pop_back();
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backTracking(nums, 0, used);
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
  vector<int> nums{1, 2, 2};
  printRes(s.subsetsWithDup(nums));
  return 0;
}

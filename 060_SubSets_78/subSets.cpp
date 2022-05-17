/**
 * leetcode : 78
 * Descrip	 : subSet problem is a partition problem.
 * Paragra  : Bohn Chen 2022-05-17 22:53
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;
  void backTracking(vector<int> &nums, int startIndex) {
    result.push_back(path);
    // 此时本身也不会进到循环中来，所以可以不加终止条件
    if (startIndex >= nums.size()) {
      return;
    }
    for (int i = startIndex; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      backTracking(nums, i + 1);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    path.clear();
    result.clear();
    backTracking(nums, 0);
    return result;
  }
};

void printResult(vector<vector<int>> res) {
  for (auto vec : res) {
    std::cout << "[ ";
    for (auto i : vec) {
      std::cout << i << " ";
    }
    std::cout << "]";
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{1, 2, 3};
  printResult(s.subsets(nums));
  return 0;
}

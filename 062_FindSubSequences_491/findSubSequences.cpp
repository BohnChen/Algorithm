/**
 * leetcode : 491
 * Descrip	 :
 * Paragra  : Bohn Chen 2022-05-19 22:26
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> path;
  vector<vector<int>> result;
  void backTracking(vector<int> &nums, int startIndex) {
    if (path.size() >= 2) {
      // if(path.size() <= nums.size())
      result.push_back(path);
      // 不返回，还需要接着取下一层的结点
    }
    // unordered_set<int> uset;
    int used[201]{0}; // 数值范围在[-100, 100]所以可以使用数组来做哈系优化
    for (int i = startIndex; i < nums.size(); ++i) {
      if ((!path.empty() && nums[i] < path.back()) ||
          /* uset.find(nums[i]) != uset.end()*/ used[nums[i] + 100] == 1) {
        continue;
      }
      path.push_back(nums[i]);
      // uset.insert(nums[i]);
      used[nums[i] + 100] = 1; // 位图思想记录这个值是否在本枝上被使用过
      backTracking(nums, i + 1);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    path.clear();
    result.clear();
    backTracking(nums, 0);
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
  vector<int> nums{4, 6, 7, 7};
  printRes(s.findSubsequences(nums));
  return 0;
}

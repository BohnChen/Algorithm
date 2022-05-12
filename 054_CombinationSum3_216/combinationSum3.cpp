/**
 * leetcode : 216
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-05-11 23:10
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(int targetSum, int k, int sum, int startIndex) {
    if (path.size() == k) {
      if (sum == targetSum)
        result.push_back(path);
      return;
    }

    for (int i = startIndex; i <= 9; ++i) {
      // for(int i = startIndex; i <= 9 - (k - path.size()) + 1; ++i) {

      sum += i;
      path.push_back(i);
      backtracking(targetSum, k, sum, i + 1);
      sum -= i;
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    result.clear();
    path.clear();
    backtracking(n, k, 0, 1);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  for (auto vec : s.combinationSum3(3, 7)) {
    std::cout << "[";
    for (auto i : vec) {
      std::cout << i << " ";
    }
    std::cout << "]";
  }

  return 0;
}

/**
 * leetcode : 77
 * Descrip	 : From now, backtracking is showing on.
 * Paragra  : Bohn Chen 2022-05-10 21:58
 */
#include <iostream>
#include <queue>
using namespace std;

//
class Solution {
private:
  vector<int> path;
  vector<vector<int>> result;
  void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex; i <= n; ++i) {
      path.push_back(i);
      backtracking(n, k, i + 1);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    result.clear();
    path.clear();
    backtracking(n, k, 1);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int n = 5, k = 2;
  for (auto vec_1 : s.combine(n, k)) {
    std::cout << "[ ";
    for (auto i : vec_1) {
      std::cout << i << " ";
    }
    std::cout << "]" << endl;
  }

  return 0;
}

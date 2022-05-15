/**
 * leetcode : 131
 * Descrip	 : 分割回文串
 * Paragra  : Bohn Chen 2022-05-15 23:13
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  vector<string> path;
  vector<vector<string>> result;
  void backTracking(const string &s, int startIndex) {
    if (startIndex >= s.size()) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex; i < s.size(); ++i) {
      if (isPalindrome(s, startIndex, i)) {
        // 取出字串
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
      } else {
        continue;
      }
      backTracking(s, i + 1);
      path.pop_back();
    }
  }

  bool isPalindrome(const string &s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }

public:
  vector<vector<string>> partition(string s) {
    result.clear();
    path.clear();
    backTracking(s, 0);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string str = "aab";
  for (auto vec : s.partition(str)) {
    std::cout << "[ ";
    for (auto st : vec) {

      std::cout << st << " ";
    }
    std::cout << "]";
  }
  return 0;
}

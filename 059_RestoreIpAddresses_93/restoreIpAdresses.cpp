/**
 * leetcode : 93
 * Descrip	 : It is too much about logic.
 * Paragra  : Bohn Chen 2022-05-16 23:36
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
  vector<string> result;
  void backTracking(string s, int startIndex, int pointNum) {
    // The entrance of recursive
    if (pointNum == 3) {
      if (isValid(s, startIndex, s.size() - 1)) {
        result.push_back(s);
      }
      return;
    }
    for (int i = startIndex; i < s.size(); ++i) {
      // Verify the substrint in [startIndex, i] is valid or not
      if (isValid(s, startIndex, i)) {
        // insert a "." after the index i
        s.insert(s.begin() + i + 1, '.');
        ++pointNum;
        backTracking(s, i + 2, pointNum);
        --pointNum;
        s.erase(s.begin() + i + 1);

      } else {
        // exit if it is not valid.
        break;
      }
    }
  }

  bool isValid(string s, int start, int end) {
    if (start > end) {
      return false;
    }
    if (s[start] == '0' && start != end) {
      return false;
    }
    int num = 0;
    for (int i = start; i <= end; ++i) {
      if (s[i] > '9' || s[i] < '0') {
        return false;
      }
      num = num * 10 + (s[i] - '0');
      if (num > 255) {
        return false;
      }
    }
    return true;
  }

public:
  vector<string> restoreIpAddresses(string s) {
    result.clear();
    if (s.size() > 12)
      return result;
    backTracking(s, 0, 0);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string str = "101023";
  for (auto st : s.restoreIpAddresses(str)) {
    std::cout << "[" << st << "]" << std::endl;
  }
  return 0;
}

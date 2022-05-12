/**
 * leetcode : 17
 * Descrip	 : 回溯的又一个例子，现在对它又理解了一些了
 * Paragra  : Bohn Chen 2022-05-12 22:12
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
  const string letterMap[10]{
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
  };

public:
  vector<string> result;
  string s;
  void backTracking(const string &digits, int index) {
    if (index == digits.size()) {
      result.push_back(s);
      return;
    }
    // 从左到右依次将对应的字符串转化为 int 型
    int digit = digits[index] - '0';
    // 获取数字对应的字符集
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); ++i) {
      s.push_back(letters[i]);
      backTracking(digits, index + 1);
      s.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    s.clear();
    result.clear();
    if (digits.size() == 0) {
      return result;
    }
    backTracking(digits, 0);
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string digits = "23";
  std::cout << "All combinations is : " << std::endl;
  for (auto s : s.letterCombinations(digits)) {
    std::cout << "[" << s << "]";
  }
  return 0;
}

/**
 * leetcode : 738
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-06-04 18:58
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    string strNum = to_string(n);
    int flag = strNum.size();
    for (int i = strNum.size() - 1; i > 0; --i) {
      if (strNum[i - 1] > strNum[i]) {
        flag = i;
        strNum[i - 1]--;
      }
    }
    for (int i = flag; i < strNum.size(); ++i) {
      strNum[i] = '9';
    }
    return stoi(strNum);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int n = 10;
  std::cout << "The result is " << s.monotoneIncreasingDigits(n) << std::endl;
  return 0;
}

/**
 * leetcode : 455
 * Descrip	 : greedy algorithm exercise.
 * Paragra  : Bohn Chen 2022-05-24 22:06
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    // s contains the size of all cookies
    // g contains the greed of all children content with
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int result = 0;
    int index = s.size() - 1;
    for (int i = g.size() - 1; i >= 0; --i) {
      if (index >= 0 && g[i] <= s[index]) {
        --index;
        ++result;
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution mySolution;
  vector<int> g{1, 2, 3};
  // the greed of children.
  vector<int> s{1, 1};
  std::cout << "The result is " << mySolution.findContentChildren(g, s)
            << std::endl;
  return 0;
}

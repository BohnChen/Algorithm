/**
 * leetcode : 452
 * Descrip	 : It is essential that find the lowest bordern.
 * Paragra  : Bohn Chen 2022-06-02 22:08
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
  }

public:
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.size() == 0) {
      return 0;
    }
    // So the time complexity is O(nLogn),quicksort
    sort(points.begin(), points.end(), cmp);
    int result = 1;
    for (int i = 1; i < points.size(); ++i) {
      // find the last folding bolloon.
      if (points[i][0] > points[i - 1][1]) {
        ++result;
      } else { // see the next one.
        // get the lowest bordern that meeting our demand
        points[i][1] = min(points[i - 1][1], points[i][1]);
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  std::cout << "We need " << s.findMinArrowShots(points)
            << " arrows minimally to shot all bolloons." << std::endl;

  return 0;
}

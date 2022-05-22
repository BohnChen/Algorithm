/**
 * leetcode : 51
 * Descrip	 : Classic problem: NQueues.
 * Paragra  : Bohn Chen 2022-05-22 21:30
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<string>> result;
  // n 为输入的棋盘的大小
  // row 表示当前递归到棋盘的第几行
  void backTracking(int n, int row, vector<string> &chessboard) {
    if (row == n) {
      result.push_back(chessboard);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (isValid(row, col, chessboard, n)) {
        // 合法就可以放置皇后
        chessboard[row][col] = 'Q';
        backTracking(n, row + 1, chessboard);
        chessboard[row][col] = '.';
      }
    }
  }

  bool isValid(int row, int col, vector<string> &chessboard, int n) {
    int count = 0;
    // 检查列
    for (int i = 0; i < row; ++i) {
      if (chessboard[i][col] == 'Q') {
        return false;
      }
    }

    // 检查 45 度角直线是否有皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    // 检查 135 度角直线是否有皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    result.clear();
    vector<string> chessboard(n, string(n, '.'));
    backTracking(n, 0, chessboard);
    return result;
  }
};

void printRes(const vector<vector<string>> &res) {
  // std::cout << "[ ";
  for (auto vec : res) {
    // std::cout << "[ ";
    for (string i : vec) {
      std::cout << i << " " << endl;
    }
    std::cout << std::endl;
  }
  // std::cout << " ]";
}

int main(int argc, char *argv[]) {
  Solution s;
  int n = 4;
  printRes(s.solveNQueens(n));
  return 0;
}

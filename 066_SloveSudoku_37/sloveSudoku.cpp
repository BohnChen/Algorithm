/**
 * leetcode : 37
 * Descrip	 : The first time to see two-dimensional recursive.
 * Paragra  : Bohn Chen 2022-05-23 23:08
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  bool backTracking(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] != '.')
          continue;
        for (char k = '1'; k <= '9'; ++k) {
          if (isValid(i, j, k, board)) {
            board[i][j] = k;
            // 如果找到一组合适的值就立即返回
            if (backTracking(board))
              return true;
            // 回溯
            board[i][j] = '.';
          }
        }
        // 如果 9 个数都试完了，都不行，那么就返回 false
        return false;
      }
    }
    return true;
  }

  bool isValid(int row, int col, char val, vector<vector<char>> &board) {
    // 判断同一行中是否有重复的数
    for (int i = 0; i < 9; ++i) {
      if (board[row][i] == val) {
        return false;
      }
    }

    // 判断同一列中是否有重复的数
    for (int j = 0; j < 9; ++j) {
      if (board[j][col] == val) {
        return false;
      }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    // 判断 9 宫格中是否有重复的数
    for (int i = startRow; i < startRow + 3; ++i) {
      for (int j = startCol; j < startCol + 3; ++j) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }
    return true;
  }

public:
  void solveSudoku(vector<vector<char>> &board) { backTracking(board); }
};

void printRes(const vector<vector<char>> &res) {
  // std::cout << "[ ";
  for (auto vec : res) {
    // std::cout << "[ ";
    for (char i : vec) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  // std::cout << " ]";
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  s.solveSudoku(board);
  printRes(board);
  return 0;
}

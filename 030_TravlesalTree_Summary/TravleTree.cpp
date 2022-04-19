/**
 * leetcode : num
 * Descrip	 : 使用迭代法写出前后中序遍历的统一风格代码
 * Paragra  : Bohn Chen 2022-04-19 17:21
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *createTree(std::vector<TreeNode *> &treeVec, int size) {
  // 快慢指针建立树
  // 给慢指针赋值左右，左右是快指针指向的值
  for (int slow = 0, fast = 1; fast < size; ++slow) {
    treeVec[slow]->left = treeVec[fast++];
    if (fast == size)
      break;
    else
      treeVec[slow]->right = treeVec[fast++];
  }
  return treeVec[0];
}

vector<int> PreOrderedTravlesal(TreeNode *root) { return {}; }

vector<int> InOrderedTravlesal(TreeNode *root) { return {}; }

vector<int> PostOrderedTravlesal(TreeNode *root) { return {}; }

int main(int argc, char *argv[]) {

  vector<TreeNode *> treeVec{new TreeNode(3), new TreeNode(9), new TreeNode(20),
                             nullptr,         nullptr,         new TreeNode(15),
                             new TreeNode(7)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  for (int node : PreOrderedTravlesal(root)) {
    std::cout << node << " ";
  }
  return 0;
}

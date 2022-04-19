/**
 * leetcode : 102
 * Descrip	 : Implement level order with queue
 * Paragra  : Bohn Chen 2022-04-19 22:19
 */
#include <iostream>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root) {
  queue<TreeNode *> que;
  if (root)
    que.push(root);
  vector<vector<int>> result;
  while (!que.empty()) {
    int size = que.size();
    vector<int> vec;
    for (int i = 0; i < size; ++i) {
      TreeNode *pTemp = que.front();
      que.pop();
      vec.push_back(pTemp->val);
      if (pTemp->left)
        que.push(pTemp->left);
      if (pTemp->right)
        que.push(pTemp->right);
    }
    result.push_back(vec);
  }
  return result;
}

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

int main(int argc, char *argv[]) {
  vector<TreeNode *> treeVec{new TreeNode(3), new TreeNode(9), new TreeNode(20),
                             nullptr,         nullptr,         new TreeNode(15),
                             new TreeNode(7)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  for (auto vec_1 : levelOrder(root)) {
    std::cout << "[ ";
    for (auto vec_2 : vec_1) {
      std::cout << vec_2 << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
  }

  return 0;
}

/**
 * leetcode : 104
 * Descrip	 : 递归写法的三个步骤+迭代法的逻辑
 * Paragra  : Bohn Chen 2022-04-22 19:28
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

int maxDepthIterative(TreeNode *root) {
  if (!root)
    return 0;
  queue<TreeNode *> que;
  int depth = 1;
  if (root->left)
    que.push(root->left);
  if (root->right)
    que.push(root->right);
  while (!que.empty()) {
    int size = que.size();
    ++depth;
    for (int i = 0; i < size; ++i) {
      TreeNode *Node = que.front();
      que.pop();

      if (Node->left)
        que.push(Node->left);
      if (Node->right)
        que.push(Node->right);
    }
  }
  return depth;
}

// 1、确定函数参数和返回值
// 2、确定递归退出条件
// 3、确定单层逻辑

int getDepth(TreeNode *root) {
  if (!root)
    return 0;
  int leftDepth = getDepth(root->left);
  int rightDepth = getDepth(root->right);
  int maxDepth = 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
  return maxDepth;
}

int maxDepth(TreeNode *root) { return getDepth(root); }

TreeNode *createTree(vector<TreeNode *> &treeVec, int size) {
  for (int slow = 0, fast = 1; fast < size; ++slow) {
    // Skip the nullptr.
    while (treeVec[slow] == nullptr) {
      ++slow;
    }
    treeVec[slow]->left = treeVec[fast++];
    if (fast == size) {
      break;
    } else {
      treeVec[slow]->right = treeVec[fast++];
    }
  }
  return treeVec[0];
}
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

void printTreeNode(TreeNode *root) {
  for (auto vec_1 : levelOrder(root)) {
    std::cout << "[ ";
    for (auto vec_2 : vec_1) {
      std::cout << vec_2 << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
  }
}
int main(int argc, char *argv[]) {
  vector<TreeNode *> treeVec{new TreeNode(3), new TreeNode(9), new TreeNode(20),
                             nullptr,         nullptr,         new TreeNode(15),
                             new TreeNode(7)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTreeNode(root);
  cout << " The max depth of the given tree is " << maxDepth(root) << endl;

  return 0;
}

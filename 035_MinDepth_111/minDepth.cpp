/**
 * leetcode : 111
 * Descrip	 : You shold handle the real min depth when using recurve
 * method; Iterative method is like that in MaxDepth Paragra  : Bohn Chen
 * 2022-04-22 22:27
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

// Iterative method
int minDepthIterative(TreeNode *root) {
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
      TreeNode *node = que.front();
      que.pop();
      if (node->left)
        que.push(node->left);
      if (node->right)
        que.push(node->right);
      if (!node->left && !node->right) {
        return depth;
      }
    }
  }
  return depth;
}
// recurve
int getDepth(TreeNode *root) {
  if (!root)
    return 0;
  int left = getDepth(root->left);
  int right = getDepth(root->right);
  // 为单支的二叉树时候，1 并不是其最小深度
  // 左子树为空，右子树不空时，右子树深度才是当前最小深度
  if (!root->left && root->right) {
    return 1 + right;
  }
  // 同理，当右子树为空，左子树不为空时候，左子树深度才是当前最小深度
  if (!root->right && root->left) {
    return 1 + left;
  }
  int result = 1 + (left < right ? left : right);
  return result;
}

int minDepth(TreeNode *root) { return getDepth(root); }

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
  // vector<TreeNode *> treeVec{new TreeNode(3), new TreeNode(9), new
  // TreeNode(20),
  //                            nullptr,         nullptr,         new
  //                            TreeNode(15), new TreeNode(7)}; // min is 2
  vector<TreeNode *> treeVec{new TreeNode(2), nullptr, new TreeNode(3), nullptr,
                             new TreeNode(4), nullptr, new TreeNode(5), nullptr,
                             new TreeNode(6)}; // min is 5
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTreeNode(root);
  cout << " The max depth of the given tree is " << minDepth(root) << endl;

  return 0;
}

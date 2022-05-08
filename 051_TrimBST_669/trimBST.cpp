/**
 * leetcode : 669
 * Descrip	 : Recursivly delete node out of a special range  using
 * properties of BST. Paragra  : Bohn Chen 2022-05-08 21:58
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  // Recursive method
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (root == nullptr)
      return nullptr;
    if (root->val < low)
      return trimBST(root->right, low, high);
    if (root->val > high)
      return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }

  TreeNode *trimBSTIterative(TreeNode *root, int low, int high) {
    if (root == nullptr)
      return nullptr;
    // 保证 root 是符合要求的
    while (root != nullptr && (root->val < low || root->val > high)) {
      if (root->val < low)
        root = root->right;
      else
        root = root->left;
    }
    TreeNode *pCur = root;
    // 处理左子树
    while (pCur != nullptr) {
      while (pCur->left != nullptr && pCur->left->val < low) {
        pCur->left = pCur->left->right;
      }
      // 如果当前结点已经满足条件，对更小的结点进行操作
      pCur = pCur->left;
    }
    // 处理右子树
    pCur = root;
    while (pCur != nullptr) {
      while (pCur->right && pCur->right->val > high) {
        pCur->right = pCur->right->left;
      }
      // 如果当前结点已经满足条件，对更大的结点进行操作
      pCur = pCur->right;
    }
    return root;
  }
};
#if 1
// Create a tree according to a vector
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
vector<vector<string>> printTreeNode(TreeNode *root, int VecSize) {
  queue<TreeNode *> que;
  if (root)
    que.push(root);
  vector<vector<string>> result;
  while (!que.empty()) {
    int size = que.size();
    vector<string> vec;
    for (int i = 0; i < size; ++i) {
      TreeNode *pTemp = que.front();
      que.pop();
      if (pTemp) {
        vec.push_back(to_string(pTemp->val));
        if (pTemp->left)
          que.push(pTemp->left);
        else
          que.push(nullptr);
        if (pTemp->right)
          que.push(pTemp->right);
        else
          que.push(nullptr);
      } else {
        vec.push_back("null");
      }
    }
    result.push_back(vec);
  }
  return result;
}

void printTree(TreeNode *root, int size) {
  for (auto vec_1 : printTreeNode(root, size)) {
    std::cout << "[ ";
    for (auto vec_2 : vec_1) {
      std::cout << vec_2 << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
  }
}
#endif

int main(int argc, char *argv[]) {
  // 1,0,2
  // 1
  // 2
  vector<TreeNode *> treeVec{new TreeNode(1), new TreeNode(0), new TreeNode(2)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  std::cout << "Before delete." << std::endl;
  printTree(root, treeVec.size());
  Solution s;
  std::cout << "After delete." << std::endl;
  printTree(s.trimBSTIterative(root, 1, 2), treeVec.size());
  return 0;
}

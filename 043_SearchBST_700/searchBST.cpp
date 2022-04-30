/**
 * leetcode : 700
 * Descrip	 : easyyyy.
 * Paragra  : Bohn Chen 2022-04-30 21:16
 */
#include <iostream>
#include <queue>
#include <string>
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

TreeNode *searchRecurveBST(TreeNode *root, int val) {
  if (!root)
    return nullptr;
  if (root->val < val)
    return searchRecurveBST(root->right, val);
  if (root->val > val)
    return searchRecurveBST(root->left, val);
  return root;
}

TreeNode *searchIterativeBST(TreeNode **root, int val) {
  while (*root) {
    if ((*root)->val > val)
      (*root) = (*root)->left;
    else if ((*root)->val < val)
      (*root) = (*root)->right;
    else
      return (*root);
  }
  return *root;
}

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

  vector<TreeNode *> treeVec1{new TreeNode(4), new TreeNode(2), new TreeNode(7),
                              new TreeNode(1), new TreeNode(3)};
  TreeNode *root = createTree(treeVec1, treeVec1.size());
  printTree(root, treeVec1.size());
  std::cout << std::endl;
  int val = 2;
  searchIterativeBST(&root, val);
  if (root)
    std::cout << "The val is found. The val is " << root->val << std::endl;
  else
    std::cout << "The val is not found." << std::endl;

  return 0;
}

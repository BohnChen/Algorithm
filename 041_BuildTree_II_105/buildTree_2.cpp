/**
 * leetcode : 105
 * Descrip	 : The same as buildTree, it is that how to separite the
 * traversal vectors matters Paragra  : Bohn Chen 2022-04-28 18:33
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

TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd,
                    vector<int> &preorder, int preorderBegin, int preorderEnd) {
  if (inorderEnd == inorderBegin)
    return NULL;

  // 先找到根节点
  int rootValue = preorder[preorderBegin];
  TreeNode *root = new TreeNode(rootValue);

  if (preorderEnd - preorderBegin == 1)
    return root;

  // 分割中序遍历的数组
  int delimiterIndex;
  for (delimiterIndex = 0; delimiterIndex < inorderEnd; ++delimiterIndex) {
    if (inorder[delimiterIndex] == rootValue)
      break;
  }

  // 找到左中序, 左闭右开
  int leftInorderBegin = inorderBegin;
  int leftInorderEnd = delimiterIndex;
  // 找到右中序，左闭右开
  int rightInorderBegin = delimiterIndex + 1;
  int rightInorderEnd = inorderEnd;

  // 分割前序遍历的数组
  int leftPreorderBegin = preorderBegin + 1;
  // 起始位置加上中序左区间的长度
  int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
  // 由于是左闭右开，起始位置加上中序左区间的长度
  int rightPreorderBegin = preorderBegin + 1 + delimiterIndex - inorderBegin;
  int rightPreorderEnd = preorderEnd;

  root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder,
                         leftPreorderBegin, leftPreorderEnd);
  root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder,
                          rightPreorderBegin, rightPreorderEnd);

  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  if (preorder.size() == 0 || inorder.size() == 0)
    return NULL;
  return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
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
#endif

int main(int argc, char *argv[]) {
  vector<int> PreVec{3, 9, 20, 15, 7};
  vector<int> InVec{9, 3, 15, 20, 7};

  std::cout << "The levelOrder of the tree is : " << std::endl;
  TreeNode *root = buildTree(PreVec, InVec);
  printTreeNode(root);

  return 0;
}

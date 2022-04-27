/**
 * leetcode : 106
 * Descrip	 : You should know the defination of trversal
 * Paragra  : Bohn Chen 2022-04-27 21:21
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
// 中序区间：[inorderBegin, inorderEnd)，后序区间[postorderBegin,
// postorderEnd)
TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd,
                    vector<int> &postorder, int postorderBegin,
                    int postorderEnd) {
  if (postorderBegin == postorderEnd)
    return NULL;

  int rootValue = postorder[postorderEnd - 1];
  TreeNode *root = new TreeNode(rootValue);

  if (postorderEnd - postorderBegin == 1)
    return root;

  int delimiterIndex;
  for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd;
       delimiterIndex++) {
    if (inorder[delimiterIndex] == rootValue)
      break;
  }
  // 切割中序数组
  // 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
  int leftInorderBegin = inorderBegin;
  int leftInorderEnd = delimiterIndex;
  // 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
  int rightInorderBegin = delimiterIndex + 1;
  int rightInorderEnd = inorderEnd;

  // 切割后序数组
  // 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
  int leftPostorderBegin = postorderBegin;
  int leftPostorderEnd = postorderBegin + delimiterIndex -
                         inorderBegin; // 终止位置是 需要加上 中序区间的大小size
  // 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
  int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
  int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

  root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder,
                         leftPostorderBegin, leftPostorderEnd);
  root->right = traversal(inorder, rightInorderBegin, rightInorderEnd,
                          postorder, rightPostorderBegin, rightPostorderEnd);

  return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  if (inorder.size() == 0 || postorder.size() == 0)
    return NULL;
  return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
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
  vector<int> InVec{9, 3, 15, 20, 7};
  vector<int> PostVec{9, 15, 7, 20, 3};

  TreeNode *root = buildTree(InVec, PostVec);
  printTreeNode(root);

  return 0;
}

/**
 * leetcode : 226
 * Descrip	 : 迭代， 递归， 层序遍历
 * Paragra  : Bohn Chen 2022-04-20 17:55
 */
#include <iostream>
#include <queue>
#include <stack>
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

// 层序遍历实现
TreeNode *invertTreeLevelOrder(TreeNode *root) {
  queue<TreeNode *> que;
  if (root)
    que.push(root);
  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      TreeNode *node = que.front();
      que.pop();
      swap(node->left, node->right);
      if (node->left)
        que.push(node->left);
      if (node->right)
        que.push(node->right);
    }
  }
  return root;
}

// 迭代法实现
TreeNode *invertTree(TreeNode *root) {
  if (!root)
    return root;
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty()) {
    TreeNode *node = st.top();
    st.pop();
    swap(node->left, node->right);
    if (node->left)
      st.push(node->left);
    if (node->right)
      st.push(node->right);
  }
  return root;
}

TreeNode *invertTreeRecurve(TreeNode *root) {
  if (root == NULL)
    return root;
  swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
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

  vector<TreeNode *> treeVec{
      new TreeNode(4), new TreeNode(2), new TreeNode(7), new TreeNode(1),
      new TreeNode(3), new TreeNode(6), new TreeNode(9),
  };
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTreeNode(root);
  root = invertTreeRecurve(root);
  printTreeNode(root);
  return 0;
}

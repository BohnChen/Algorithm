/**
 * leetcode : 101
 * Descrip	 : Use recurve and iterative methods slove it
 * Paragra  : Bohn Chen 2022-04-21 22:38
 */
#include <iostream>
#include <queue>
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
/*  // recurve
    bool compare(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;
        else if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left->val != right->val) return false;

        // Now both left and right are not NULL
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;

        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
*/
/*
    // queue
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()) {
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            // 左右结点为空时对称，可以直接返回 true;
            if(leftNode == nullptr && rightNode == nullptr) {
                continue;
            }
            // 不对称的情况时候，直接返回false;
            if(!leftNode || !rightNode || leftNode->val != rightNode->val) {
                return false;
            }
            // 添加两个结点的两个孩子
            que.push(leftNode->left);
            que.push(rightNode->right); // 上两个进行比较
            que.push(leftNode->right);
            que.push(rightNode->left);  // 后两个进行比较
        }
        return true;
    }
*/
// stack
bool isSymmetric(TreeNode *root) {
  if (root == nullptr)
    return true;
  stack<TreeNode *> st;
  st.push(root->left);
  st.push(root->right);
  while (!st.empty()) {
    TreeNode *leftNode = st.top();
    st.pop();
    TreeNode *rightNode = st.top();
    st.pop();
    if (leftNode == nullptr && rightNode == nullptr) {
      continue;
    }
    if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
      return false;
    }
    st.push(leftNode->right);
    st.push(rightNode->left);
    st.push(rightNode->right);
    st.push(leftNode->left);
  }
  return true;
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
TreeNode *createTree(std::vector<TreeNode *> &treeVec, int size) {
  // 快慢指针建立树
  // 给慢指针赋值左右，左右是快指针指向的值
  for (int slow = 0, fast = 1; fast < size; ++slow) {
    while (treeVec[slow] == nullptr) {
      ++slow;
    }
    treeVec[slow]->left = treeVec[fast++];
    if (fast == size)
      break;
    else
      treeVec[slow]->right = treeVec[fast++];
  }
  return treeVec[0];
}

int main(int argc, char *argv[]) {
  vector<TreeNode *> treeVec{
      new TreeNode(9),  new TreeNode(-42), new TreeNode(-42), nullptr,
      new TreeNode(76), new TreeNode(76),  nullptr,           nullptr,
      new TreeNode(13), nullptr,           new TreeNode(13)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTreeNode(root);
  if (isSymmetric(root))
    std::cout << "The tree is symmetric." << std::endl;
  else
    std::cout << "The tree isn't symetric." << std::endl;

  return 0;
}

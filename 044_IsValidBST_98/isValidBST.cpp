/**
 * leetcode : 98
 * Descrip	 : Inorder Traversal is needed
 * Paragra  : Bohn Chen 2022-05-01 20:37
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

// Recurve
TreeNode *pre = nullptr;
bool isValidBSTRecurve(TreeNode *root) {
  if (!root)
    return true;
  bool left = isValidBSTRecurve(root->left);
  // 二叉搜索树的中序遍历是有序的！
  if (pre != NULL && pre->val >= root->val)
    return false;
  pre = root;

  bool right = isValidBSTRecurve(root->right);
  return left & right;
}
// Itreative
bool isValidBST(TreeNode *root) {
  stack<TreeNode *> st;
  TreeNode *pCur = root;
  TreeNode *pPre = NULL;
  while (pCur != NULL || !st.empty()) {
    if (pCur != NULL) {
      st.push(pCur);
      pCur = pCur->left;
    } else {
      pCur = st.top();
      st.pop();
      if (pPre != NULL && pCur->val <= pPre->val)
        return false;
      pPre = pCur;
      pCur = pCur->right;
    }
  }
  return true;
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
  /*  这四个比较典型
                  [32,26,47,19,null,null,56,null,27]
                  [5,1,4,null,null,3,6]
                  [2,2,2]
                  [5,4,6,null,null,3,7]
   */
  vector<TreeNode *> treeVec{new TreeNode(2), new TreeNode(2), new TreeNode(2)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  if (isValidBST(root)) {
    std::cout << "It is a valid BST. " << std::endl;
  } else {
    std::cout << "It is not a valid BSt." << std::endl;
  }

  return 0;
}

/**
 * leetcode : 112
 * Descrip	 : Recurve and Iterative method.
 * Paragra  : Bohn Chen 2022-04-25 22:01
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

bool travlesal(TreeNode *root, int cont) {
  if (!root->left && !root->right && cont == 0)
    return true;
  if (!root->left && !root->right)
    return false;
  if (root->left) {
    cont -= root->left->val;
    if (travlesal(root->left, cont))
      return true;
    // 未返回，则要回溯
    cont += root->left->val;
  }
  if (root->right) {
    cont -= root->right->val;
    if (travlesal(root->right, cont))
      return true;
    // 未返回，则要回溯
    cont += root->right->val;
  }
  return false;
}

bool hasPathSum(TreeNode *root, int targetSum) {
  if (!root)
    return false;
  return travlesal(root, targetSum - root->val);
}

//  Iterative method
bool hasPathSumIterative(TreeNode *root, int targetSum) {
  if (!root)
    return false;
  stack<pair<TreeNode *, int>> st;
  st.push(pair<TreeNode *, int>(root, root->val));
  while (!st.empty()) {
    TreeNode *node = st.top().first;
    int sum = st.top().second;
    st.pop();
    if (!node->left && !node->right && targetSum == sum)
      return true;

    if (node->right) {
      st.push(pair<TreeNode *, int>(node->right, sum + node->right->val));
    }
    if (node->left) {
      st.push(pair<TreeNode *, int>(node->left, sum + node->left->val));
    }
  }
  return false;
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

  vector<TreeNode *> treeVec{new TreeNode(1), new TreeNode(2), new TreeNode(3)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTreeNode(root);
  int TargetSum = 5;
  if (hasPathSum(root, TargetSum)) {
    std::cout << "There is a path meet the demand. Target Sum is " << TargetSum
              << std::endl;
  } else {
    std::cout << "There is a path meet the demand." << std::endl;
  }

  return 0;
}

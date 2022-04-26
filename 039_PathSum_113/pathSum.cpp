/**
 * leetcode : 113
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-04-26 18:03
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

vector<vector<int>> result;
vector<int> path;
// 递归函数不需要返回值，因为要遍历整棵树
void traversal(TreeNode *pCur, int count) {
  // 遇到叶子结点且找到了和为 sum 的路径
  if (!pCur->left && !pCur->right && count == 0) {
    result.push_back(path);
    return;
  }
  if (!pCur->left && !pCur->right)
    return;
  if (pCur->left) {
    path.push_back(pCur->left->val);
    count -= pCur->left->val;
    traversal(pCur->left, count); // 递归
    count += pCur->left->val;     // 回溯
    path.pop_back();              // 回溯
  }
  if (pCur->right) {
    path.push_back(pCur->right->val);
    count -= pCur->right->val;
    traversal(pCur->right, count); // 递归
    count += pCur->right->val;     // 回溯
    path.pop_back();               // 回溯
  }
  return;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
  result.clear();
  path.clear();
  if (root == NULL)
    return result;
  path.push_back(root->val); // 把根节点放入路径
  traversal(root, targetSum - root->val);
  return result;
}

void printPath() {
  for (vector<int> vec1 : result) {
    for (int val : vec1) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
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

  vector<TreeNode *> treeVec{
      new TreeNode(5), new TreeNode(4),  new TreeNode(8), new TreeNode(11),
      nullptr,         new TreeNode(13), new TreeNode(4), new TreeNode(7),
      new TreeNode(2), nullptr,          nullptr,         new TreeNode(5),
      new TreeNode(11)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  std::cout << "The levelOrder of the tree is : " << std::endl;
  printTreeNode(root);
  int TargetSum = 22;
  pathSum(root, TargetSum);
  std::cout << "The path include : " << std::endl;
  printPath();
  return 0;
}

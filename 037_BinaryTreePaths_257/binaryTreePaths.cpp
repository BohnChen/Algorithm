/**
 * leetcode : 257
 * Descrip	 : The show of backforth
 * Paragra  : Bohn Chen 2022-04-24 23:07
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
class Solution {
private:
  void traversal(TreeNode *pCur, vector<int> &path, vector<string> &result) {
    path.push_back(pCur->val);
    // 叶子结点
    if (!pCur->left && !pCur->right) {
      string sPath;
      for (int i = 0; i < path.size() - 1; ++i) {
        sPath += to_string(path[i]);
        sPath += "->";
      }
      // 最后是以数字的字符串结尾
      sPath += to_string(path[path.size() - 1]);
      result.push_back(sPath);
      return;
    }

    if (pCur->left) {
      traversal(pCur->left, path, result);
      path.pop_back(); // 回溯到上一个结点
    }
    if (pCur->right) {
      traversal(pCur->right, path, result);
      path.pop_back(); // 回溯
    }
  }

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root)
      return {};
    vector<string> result;
    vector<int> path;
    traversal(root, path, result);
    return result;
  }

  // Iterative method
  vector<string> binaryTreePathsIterative(TreeNode *root) {
    stack<TreeNode *> treeSt;
    stack<string> pathSt;
    vector<string> result;
    if (!root)
      return {};
    treeSt.push(root);
    pathSt.push(to_string(root->val));
    while (!treeSt.empty()) {
      TreeNode *node = treeSt.top();
      treeSt.pop();
      string path = pathSt.top();
      pathSt.pop();
      if (!node->left && !node->right) {
        result.push_back(path);
      }
      if (node->right) {
        treeSt.push(node->right);
        pathSt.push(path + "->" + to_string(node->right->val));
      }
      if (node->left) {
        treeSt.push(node->left);
        pathSt.push(path + "->" + to_string(node->left->val));
      }
    }
    return result;
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

  vector<TreeNode *> treeVec{new TreeNode(1), new TreeNode(2), new TreeNode(2),
                             new TreeNode(3), new TreeNode(3), nullptr,
                             nullptr,         new TreeNode(4), new TreeNode(4)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTreeNode(root);
  Solution s;
  std::cout << std::endl;
  std::cout << "All paths of the binary tree is : " << std::endl;
  for (auto s : s.binaryTreePathsIterative(root)) {
    std::cout << s << endl;
  }
  return 0;
}

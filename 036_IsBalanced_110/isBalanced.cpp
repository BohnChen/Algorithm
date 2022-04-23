/**
 * leetcode : 110
 * Descrip	 : 这里我们需要区别两个概念：树的高度和深度
 *							1、递归，找高度的差值判断是否平衡
 *							2、递归 ＋ 回溯
 * Paragra  : Bohn Chen 2022-04-23 23:10
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
/*
    // maxDepth :
    int getMaxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = getMaxDepth(root->left);
        int rightDepth = getMaxDepth(root->right);
        int result = 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
        return result;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        //
   注意这里并不是最小深度和最大深度之差，如果你这样认为了，请复习关于树深度的定义
        int leftDepth = getMaxDepth(root->left);
        int rightDepth = getMaxDepth(root->right);
        cout << leftDepth << "  " << rightDepth << endl;
        // 精华在此，需要递归的判断每颗子树是不是平衡的来确定最终结果
        if(abs(leftDepth - rightDepth) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
*/

// backForth
int getDepth(TreeNode *node) {
  if (node == NULL) {
    return 0;
  }

  int leftDepth = getDepth(node->left);
  if (leftDepth == -1)
    return -1;
  int rightDepth = getDepth(node->right);
  if (rightDepth == -1)
    return -1;
  return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
}

bool isBalanced(TreeNode *root) { return getDepth(root) == -1 ? false : true; }

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
  // This is not a balanced tree.
  vector<TreeNode *> treeVec{new TreeNode(1), new TreeNode(2), new TreeNode(2),
                             new TreeNode(3), new TreeNode(3), nullptr,
                             nullptr,         new TreeNode(4), new TreeNode(4)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTreeNode(root);
  if (isBalanced(root))
    std::cout << "This is a balanced tree." << std::endl;
  else
    std::cout << "This is not a balanced tree." << std::endl;

  return 0;
}

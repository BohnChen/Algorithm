/**
 * leetcode : 617
 * Descrip	 : recurve to handle it. Or you can use a queue to handle it
 * with itreative thought. Paragra  : Bohn Chen 2022-04-29 22:05
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
/*
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        // 保留两颗树原先的结构
        TreeNode* root = new TreeNode();
        root->val = root1->val + root2->val;
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
*/

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
  if (!root1)
    return root2;
  if (!root2)
    return root1;

  queue<TreeNode *> que;
  que.push(root1);
  que.push(root2);
  while (!que.empty()) {
    TreeNode *node1 = que.front();
    que.pop();
    TreeNode *node2 = que.front();
    que.pop();
    // 此时两个结点一定不为空
    node1->val += node2->val;

    // 两棵树的左节点都不为空,则加入队列，等待下次的合并
    if (node1->left && node2->left) {
      que.push(node1->left);
      que.push(node2->left);
    }
    // 两棵树的右节点都不为空，则加入队列
    if (node1->right && node2->right) {
      que.push(node1->right);
      que.push(node2->right);
    }
    // 树1 的左结点为空，右结点不为空时
    if (!node1->left && node2->left) {
      node1->left = node2->left;
    }
    if (!node1->right && node2->right) {
      node1->right = node2->right;
    }
  }
  return root1;
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
  vector<TreeNode *> treeVec1{new TreeNode(1), new TreeNode(3), new TreeNode(2),
                              new TreeNode(5)};
  TreeNode *root1 = createTree(treeVec1, treeVec1.size());
  vector<TreeNode *> treeVec2{new TreeNode(2), new TreeNode(1), new TreeNode(3),
                              nullptr,         new TreeNode(4), nullptr,
                              new TreeNode(7)};
  TreeNode *root2 = createTree(treeVec2, treeVec2.size());
  std::cout << "The Traversal of tree1 is : " << std::endl;
  printTree(root1, treeVec1.size());
  std::cout << "The Traversal of tree2 is : " << std::endl;
  printTree(root2, treeVec2.size());
  mergeTrees(root1, root2);
  std::cout << "The new tree is:" << std::endl;
  printTree(root1, treeVec1.size());
  return 0;
}

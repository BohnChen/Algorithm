/**
 * leetcode : 236
 * Descrip	 : You need to review it.
 * Paragra  : Bohn Chen 2022-05-04 22:23
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // Shortly code, sophisticated structure.
    if (root == q || root == p || root == NULL)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)
      return root;

    if (left == NULL && right != NULL)
      return right;
    else if (left != NULL && right == NULL)
      return left;
    else { // left == NULL && right == NULL
      return NULL;
    }
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
  /***
   * [3,5,1,6,2,0,8,null,null,7,4]
   * 5
   * 1
   */
  vector<TreeNode *> treeVec{new TreeNode(3), new TreeNode(5), new TreeNode(1),
                             new TreeNode(6), new TreeNode(2), new TreeNode(0),
                             new TreeNode(8), nullptr,         nullptr,
                             new TreeNode(7), new TreeNode(4)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  Solution s;
  TreeNode *p = treeVec[1];
  TreeNode *q = treeVec[2];
  TreeNode *res = s.lowestCommonAncestor(root, p, q);
  if (res) {
    std::cout << "The lowestCommonAncestor is " << res->val << std::endl;
  } else {
    std::cout << "None." << std::endl;
  }

  return 0;
}

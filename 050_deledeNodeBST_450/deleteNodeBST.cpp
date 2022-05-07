/**
 * leetcode : 450
 * Descrip	 : There are many situation need to be considered
 * Paragra  : Bohn Chen 2022-05-07 20:57
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
class Solution {
private:
  TreeNode *deleteNodeOperation(TreeNode *target) {
    if (target == nullptr)
      return target;
    if (target->right == nullptr)
      return target->left;
    TreeNode *pCur = target->right;
    while (pCur->left) {
      pCur = pCur->left;
    }
    pCur->left = target->left;
    return target->right;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return root;
    TreeNode *pCur = root;
    TreeNode *pPre = nullptr;
    while (pCur) {
      if (pCur->val == key)
        break;
      pPre = pCur;
      if (pCur->val > key)
        pCur = pCur->left;
      else
        pCur = pCur->right;
    }
    if (pPre == nullptr) {
      return deleteNodeOperation(pCur);
    }
    if (pPre->left && pPre->left->val == key) {
      pPre->left = deleteNodeOperation(pCur);
    }
    if (pPre->right && pPre->right->val == key) {
      pPre->right = deleteNodeOperation(pCur);
    }
    return root;
  }

  /*
  public:
      TreeNode* deleteNode(TreeNode* root, int key) {
          if(root == nullptr) return root;
          if(root->val == key) {
              if(root->left == nullptr) return root->right;
              else if (root->right == nullptr) return root->left;
              else {
                  TreeNode* pCur = root->right;
                  while(pCur->left != nullptr) {
                      pCur = pCur->left;
                  }
                  pCur->left = root->left;
                  TreeNode* tmp = root;
                  root = root->right;
                  delete tmp;
                  return root;
              }
          }
          if(root->val < key) root->right = deleteNode(root->right, key);
          if(root->val > key) root->left = deleteNode(root->left, key);
          return root;
      }
  */
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

  // 	[5,3,6,2,4,null,7]
  //  3
  vector<TreeNode *> treeVec{new TreeNode(5), new TreeNode(3), new TreeNode(6),
                             new TreeNode(2), new TreeNode(4), nullptr,
                             new TreeNode(7)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  std::cout << "Before delete. " << std::endl;
  printTree(root, treeVec.size());
  std::cout << "After delete. " << std::endl;
  Solution s;
  s.deleteNode(root, 3);
  printTree(root, treeVec.size() - 1);
  return 0;
}

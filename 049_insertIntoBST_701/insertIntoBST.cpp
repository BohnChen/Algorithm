/**
 * leetcode : 701
 * Descrip	 : You should get the parent node to insert into the tree After
 * you find the position. Paragra  : Bohn Chen 2022-05-06 23:22
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
  TreeNode *pPre;
  void insertFunc(TreeNode *pCur, int val) {
    if (!pCur) {
      TreeNode *pNew = new TreeNode(val);
      if (!pPre) {
        pPre = pNew;
      }
      if (val > pPre->val)
        pPre->right = pNew;
      else if (val < pPre->val)
        pPre->left = pNew;
      return;
    }
    pPre = pCur;
    if (pCur->val > val) {
      insertFunc(pCur->left, val);
    } else if (pCur->val < val) {
      insertFunc(pCur->right, val);
    }
    // return;
  }

public:
  /*
      TreeNode* insertIntoBST(TreeNode* root, int val) {
          if(!root) {
              return new TreeNode(val);
          }
          insertFunc(root, val);
          return root;
      }
  */
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == NULL) {
      return new TreeNode(val);
    }
    TreeNode *pCur = root;
    // 保存相应位置的父结点，才能进行插入
    TreeNode *pPre = nullptr;
    // 找到相应的位置
    while (pCur != NULL) {
      pPre = pCur;
      if (pCur->val > val)
        pCur = pCur->left;
      else if (pCur->val < val)
        pCur = pCur->right;
    }
    TreeNode *pNew = new TreeNode(val);
    if (val > pPre->val)
      pPre->right = pNew;
    else if (val < pPre->val)
      pPre->left = pNew;
    return root;
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

  // 	[40,20,60,10,30,50,70]
  //  25
  vector<TreeNode *> treeVec{
      new TreeNode(40), new TreeNode(20), new TreeNode(60), new TreeNode(10),
      new TreeNode(30), new TreeNode(50), new TreeNode(70)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  std::cout << "Before insert. " << std::endl;
  printTree(root, treeVec.size());
  std::cout << "After insert. " << std::endl;
  Solution s;
  s.insertIntoBST(root, 25);
  printTree(root, treeVec.size() + 1);

  return 0;
}

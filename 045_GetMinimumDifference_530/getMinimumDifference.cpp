/**
 * leetcode : 530
 * Descrip	 : You should review the iterative method.
 * Paragra  : Bohn Chen 2022-05-02 21:53
 */
#include <algorithm>
#include <climits>
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

// This is a recurve method : it get a sorted vector by inOrder travel, then get
// the minimum from vector.
vector<int> vec;
void traversalVec(TreeNode *root) {
  if (root == nullptr)
    return;
  traversalVec(root->left);
  vec.push_back(root->val);
  traversalVec(root->right);
}

int getMinimumDifferenceVec(TreeNode *root) {
  int result = INT_MAX;
  vec.clear();
  traversalVec(root);
  if (vec.size() < 2)
    return 0;
  for (int i = 1; i < vec.size(); ++i) {
    result = min(result, vec[i] - vec[i - 1]);
  }
  return result;
}

// This is also a recurce method, Differently, it keep current one and the
// previous one to get the minimum.
TreeNode *pPre = nullptr;
int resultPre = INT_MAX;
void traversalPre(TreeNode *pCur) {
  if (pCur == nullptr)
    return;
  traversalPre(pCur->left);
  if (pPre != nullptr) {
    resultPre = min(resultPre, pCur->val - pPre->val);
  }
  pPre = pCur;
  traversalPre(pCur->right);
}

int getMinimumDifferencePre(TreeNode *root) {
  traversalPre(root);
  return resultPre;
}

// This a iterative method. It is somehow sophisticated, and it needs some time
// to get it.
int getMinimumDifferenceIterative(TreeNode *root) {
  stack<TreeNode *> st;
  TreeNode *pCur = root;
  TreeNode *pPre = NULL;
  int result = INT_MAX;
  // pCur != NULL
  while (pCur || !st.empty()) {
    if (pCur) {
      st.push(pCur);
      pCur = pCur->left;
    } else {
      pCur = st.top();
      st.pop();
      if (pPre != NULL) {
        result = min(result, pCur->val - pPre->val);
      }
      pPre = pCur;
      pCur = pCur->right;
    }
  }
  return result;
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
  vector<TreeNode *> treeVec{new TreeNode(4), new TreeNode(2), new TreeNode(6),
                             new TreeNode(1), new TreeNode(3)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  printTree(root, treeVec.size());
  std::cout << "The RecurveVec method get the minimum is "
            << getMinimumDifferenceVec(root) << std::endl;
  std::cout << "The RecurcePre method get the minimum is "
            << getMinimumDifferencePre(root) << std::endl;
  std::cout << "The iterative method get the minimum is "
            << getMinimumDifferenceIterative(root) << std::endl;

  return 0;
}

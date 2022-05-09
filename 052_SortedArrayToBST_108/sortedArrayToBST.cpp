/**
 * leetcode : 108
 * Descrip	 : Recursive method and a iterative one.
 * Paragra  : Bohn Chen 2022-05-09 22:07
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
  /*
  private:
      TreeNode* traversal (vector<int>& nums, int left, int right) {
          if(left > right) return nullptr;
          int mid = left + ((right - left) / 2);
          TreeNode* root = new TreeNode(nums[mid]);
          root->left = traversal(nums, left, mid - 1);
          root->right = traversal(nums, mid + 1, right);
          return root;
      }
  public:
      TreeNode* sortedArrayToBST(vector<int>& nums) {
          TreeNode* root = traversal(nums, 0, nums.size() - 1);
          return root;
      }
      */

public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0)
      return nullptr;

    TreeNode *root = new TreeNode(0); //  初始化根节点
    queue<TreeNode *> nodeQue;
    queue<int> leftQue;
    queue<int> rightQue;
    nodeQue.push(root);
    leftQue.push(0);
    rightQue.push(nums.size() - 1);

    while (!nodeQue.empty()) {
      TreeNode *curNode = nodeQue.front();
      nodeQue.pop();
      int left = leftQue.front();
      leftQue.pop();
      int right = rightQue.front();
      rightQue.pop();
      int mid = left + ((right - left) / 2);

      curNode->val = nums[mid];

      if (left <= mid - 1) {
        curNode->left = new TreeNode(0);
        nodeQue.push(curNode->left);
        leftQue.push(left);
        rightQue.push(mid - 1);
      }
      if (right >= mid + 1) {
        curNode->right = new TreeNode(0);
        nodeQue.push(curNode->right);
        leftQue.push(mid + 1);
        rightQue.push(right);
      }
    }
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
  // [-10,-3,0,5,9]
  vector<int> treeVec{-10, -3, 0, 5, 9};
  Solution s;
  printTree(s.sortedArrayToBST(treeVec), treeVec.size());

  return 0;
}

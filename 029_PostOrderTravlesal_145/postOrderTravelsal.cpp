/**
 * leetcode : 145
 * Descrip	 : Implement it with stack
 * Paragra  : Bohn Chen 2022-04-18 18:50
 */
#include <algorithm>
#include <iostream>
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
public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    stack<TreeNode *> st;
    vector<int> result;
    st.push(root);
    while (!st.empty()) {
      TreeNode *pNew = st.top();
      st.pop();
      result.push_back(pNew->val);
      if (pNew->left)
        st.push(pNew->left);
      if (pNew->right)
        st.push(pNew->right);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  /* [1, null, 2, 3] */
  TreeNode *root = new TreeNode(1);
  TreeNode *pNew_1 = new TreeNode(2);
  TreeNode *pNew_2 = new TreeNode(3);
  pNew_1->left = pNew_2;
  root->right = pNew_1;
  for (auto c : s.postorderTraversal(root)) {
    std::cout << c << " ";
  }
  std::cout << std::endl;

  return 0;
}

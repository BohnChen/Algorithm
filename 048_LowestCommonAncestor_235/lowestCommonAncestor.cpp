/**
 * leetcode : 235
 * Descrip	 : The lowestCommonAncesstor of a binary search tree
 * Paragra  : Bohn Chen 2022-05-05 21:35
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  TreeNode *traversal(TreeNode *pCur, TreeNode *p, TreeNode *q) {

    if (pCur == NULL)
      return pCur;

    if (pCur->val > p->val && pCur->val > q->val) {
      TreeNode *left = traversal(pCur->left, p, q);
      if (left != NULL) {
        return left;
      }
    }

    if (pCur->val < p->val && pCur->val < q->val) {
      TreeNode *right = traversal(pCur->right, p, q);
      if (right != NULL) {
        return right;
      }
    }
    return pCur;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return traversal(root, p, q);
  }
};

/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // 两个节点都在左边
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        // 一左一右直接返回根节点
        if((p->val < root-> val && q->val > root->val) || (p->val > root-> val
&& q->val < root->val)) return root;
        // 两个节点都在右边
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        // 两个节点是从属关系则直接返回父节点
        if(root->val == p->val)
            return p;
        if(root->val == q->val)
            return q;
        // 否则就是没有找到，或者 root 为空
        return NULL;


        // 精简之后就是这样
        if( !root || root->val >= min(p->val, q->val) && root->val <=
max(q->val,p->val) )   return root; if( root->val > max(p->val, q->val) ) return
lowestCommonAncestor(root->left, p, q); return lowestCommonAncestor(root->right,
p, q);

    }

};
*/
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
   * [6,2,8,0,4,7,9,null,null,3,5]
   * 2
   * 4
   */

  vector<TreeNode *> treeVec{new TreeNode(6), new TreeNode(2), new TreeNode(8),
                             new TreeNode(0), new TreeNode(4), new TreeNode(7),
                             new TreeNode(9), nullptr,         nullptr,
                             new TreeNode(3), new TreeNode(5)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  Solution s;
  TreeNode *p = treeVec[1];
  TreeNode *q = treeVec[4];
  TreeNode *res = s.lowestCommonAncestor(root, p, q);
  if (res) {
    std::cout << "The lowestCommonAncestor is " << res->val << std::endl;
  } else {
    std::cout << "None." << std::endl;
  }
  return 0;
}

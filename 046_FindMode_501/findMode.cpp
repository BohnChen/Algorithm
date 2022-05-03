/**
 * leetcode : 501
 * Descrip	 : Three implement method about normal binary tree and search
 * binary tree. Paragra  : Bohn Chen 2022-05-03 12:15
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
      // 这个方法适用于所有的二叉树，不限于二叉搜索树
  private:
      // 这里我们采用了中序遍历，在这里三种遍历方式都可
      void traversal(TreeNode *pCur, unordered_map<int, int>& map) {
          if(pCur == nullptr) return;
          traversal(pCur->left, map);
          map[pCur->val]++;       //
  当没有这条数据时，会进行插入。统计元素出现的频率 traversal(pCur->right, map);
      }
      bool static cmp(const pair<int, int>& a, const pair<int, int> b) {
          return a.second > b.second;    // 从大到小排序
      }
  public:
      vector<int> findMode(TreeNode* root) {
          unordered_map<int, int> map; // <key, times>
          traversal(root, map);
          // 将 map 用 pair 的方式存到vector中。
          vector<pair<int, int>> vec(map.begin(), map.end());
          sort(vec.begin(), vec.end(), cmp); //
  第三个参数是一个函数指针，我们可以重新定义它的行为 vector<int> result;
          result.push_back(vec[0].first);
          for(int i = 1; i < vec.size(); ++i) {
              if(vec[0].second == vec[i].second) result.push_back(vec[i].first);
              else break;
          }
          return result;
      }
  */
  /*

      // 而对于一棵二叉搜索树，你可以用它特有的方法进行处理
      //
  其中序遍历有序，相同的元素集中在一起，我们就有了边遍历，边寻找众数的可能，只跟前一个进行比较
  private:
      int count = 0; // A temp value to count the currences of a value
      int maxCount = 0; // The result;
      TreeNode* pPre;   // We still need a pre pointer
      vector<int> result;
      void traversal(TreeNode* pCur) {
          if(pCur == NULL) return;

          traversal(pCur->left);
          // mid
          if(pPre == NULL) {   // The first node
              count = 1;
          } else if (pPre->val == pCur->val) { // it occurents again
              ++count;
          } else {
              count = 1;       // A new node
          }
          pPre = pCur;
          // Handle the result
          if(count == maxCount) {
              result.push_back(pCur->val);
          }
          if(count > maxCount) {
              maxCount = count;
              result.clear();             // Trash the values in it before.
              result.push_back(pCur->val);
          }

          traversal(pCur->right);
          return ;
      }
  public:
      vector<int> findMode(TreeNode* root) {
          traversal(root);
          return result;
      }
  */

  // Iterative method has the same main idea with last one.
public:
  vector<int> findMode(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *pPre = NULL;
    TreeNode *pCur = root;
    int cnt = 0;
    int maxCnt = 0;
    vector<int> result;
    while (pCur || !st.empty()) {
      if (pCur) {
        st.push(pCur);
        pCur = pCur->left;
      } else {
        pCur = st.top();
        st.pop();
        if (pPre == NULL) {
          cnt = 1;

        } else if (pPre->val == pCur->val) {
          ++cnt;
        } else {
          cnt = 1;
        }
        if (cnt == maxCnt) {
          result.push_back(pCur->val);
        }
        if (cnt > maxCnt) {
          result.clear();
          maxCnt = cnt;
          result.push_back(pCur->val);
        }
        pPre = pCur;
        pCur = pCur->right;
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

  vector<TreeNode *> treeVec{new TreeNode(1), nullptr, new TreeNode(2),
                             new TreeNode(2)};
  TreeNode *root = createTree(treeVec, treeVec.size());
  std::cout << "The tree is : " << std::endl;
  printTree(root, treeVec.size());
  Solution s;
  // Mode : 众数
  std::cout << endl << "The Mode is : ";
  for (auto i : s.findMode(root)) {
    std::cout << i << " ";
  }
  return 0;
}

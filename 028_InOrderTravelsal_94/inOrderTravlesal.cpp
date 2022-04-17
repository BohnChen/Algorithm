/**
 * leetcode : 94
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-04-17 18:54
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
			: val(0)
			, left(nullptr)
			, right(nullptr)
	{
	}
	TreeNode(int x)
			: val(x)
			, left(nullptr)
			, right(nullptr)
	{
	}
	TreeNode(int x, TreeNode* left, TreeNode* right)
			: val(x)
			, left(left)
			, right(right)
	{
	}
};
class Solution {
	public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) {
				st.push(cur);
				cur = cur->left;
			} else {
				cur = st.top();
				st.pop();
				result.push_back(cur->val);
				cur = cur->right;
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	TreeNode* root = new TreeNode(1);
	TreeNode* pNew_2 = new TreeNode(2);
	TreeNode* pNew_3 = new TreeNode(3);
	root->left = NULL;
	root->right = pNew_2;
	pNew_2->right = pNew_3;
	Solution s;
	for (auto c : s.inorderTraversal(root)) {
		cout << c << " ";
	}
	std::cout << std::endl;
	
	
	return 0;
}

/**
 * leetcode : 144
 * Descrip	 : none
 * Paragra  : Bohn Chen 2022-04-16 21:42
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
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
	public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL)
			return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->right)
				st.push(node->right);
			if (node->left)
				st.push(node->left);
		}
		return result;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* pNew_1 = new TreeNode();
	TreeNode* pNew_2 = new TreeNode(2);
	TreeNode* pNew_3 = new TreeNode(3);
	root->left = pNew_1;
	root->right = pNew_2;
	pNew_1->left = pNew_3;
	vector<int> vec(s.preorderTraversal(root));
	for (auto c: vec) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	
	return 0;
}

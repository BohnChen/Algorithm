/**
 * Create a Binary tree and make its levelOrder is ordered.
 * Bohn Chen 2022-03-26
 */
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

#define SIZE 10

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

void quickSort(int* beg, int* end)
{
	auto left = beg;
	auto right = end - 1;
	int pivot = *(beg + (end - beg) / 2);
	do {
		while (*left < pivot)
			++left;
		while (*right > pivot)
			--right;

		if (left <= right) {
			if (left != right) {
				int temp = *left;
				*left = *right;
				*right = temp;
			}
			++left;
			--right;
		}
	} while (left <= right);
	if (beg < right)
		quickSort(beg, right + 1);
	if (end > left)
		quickSort(left, end);
}

void print(int* arr)
{
	for (int i = 0; i < 10; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

TreeNode* createTree(std::vector<TreeNode*>& treeVec)
{
	// 快慢指针建立树
	// 给慢指针赋值左右，左右是快指针指向的值
	for (int slow = 0, fast = 1; fast < SIZE; ++slow) {
		treeVec[slow]->left = treeVec[fast++];
		if (fast == SIZE)
			break;
		else
			treeVec[slow]->right = treeVec[fast++];
	}
	return treeVec[0];
}

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
	queue<TreeNode*> que;
	if (root != NULL)
		que.push(root);
	vector<vector<int>> result;
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec;
		for (int i = 0; i < size; ++i) {
			TreeNode* node = que.front();
			que.pop();
			vec.push_back(node->val);
			if (node->left)
				que.push(node->left);
			if (node->right)
				que.push(node->right);
		}
		result.push_back(vec);
	}
	return result;
}

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));
	int arr[SIZE] { 0 };
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 100;
	}
	print(arr);
	quickSort(arr, arr + SIZE);
	print(arr);

	TreeNode* root;
	// Put all Node in vector
	std::vector<TreeNode*> treeVec;
	for (int i = 0; i < SIZE; ++i) {
		TreeNode* pNew = new TreeNode(arr[i]);
		treeVec.push_back(pNew);
	}

	createTree(treeVec);
	root = treeVec[0];
	std::vector<std::vector<int>> vecv;
	vecv = levelOrder(root);
	for (auto c : vecv) {
		for (auto k : c) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

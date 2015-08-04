#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

	   1
	  / \
	 2   3
Return 6.
*/

class Solution
{
private:
	int result;
	int search(TreeNode *node)
	{
		if (node == NULL) return 0;
		int left = search(node->left);
		int right = search(node->right);
		result = ::max(result, node->val + ::max(0, left) + ::max(0, right));
		return node->val + ::max(0, ::max(left, right));
	}
public:
	int maxPathSum(TreeNode* root)
	{
		result = 0x80000000;
		search(root);
		return result;
	}
};

/*
idea: recursive tracing longest from node to its children
complexity: O(N)
*/

int main(void)
{
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(-2);
	root->right = new TreeNode(3);
	Solution engine;
	cout << engine.maxPathSum(root) << '\n';
	return 0;
}
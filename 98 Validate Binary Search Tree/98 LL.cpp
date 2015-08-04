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
https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

class Solution
{
private:
	bool search(TreeNode *node, TreeNode *min, TreeNode *max)
	{
		if (node == NULL) return true;
		int cache = node->val;
		if ((min != NULL) && (cache <= min->val)) return false;
		if ((max != NULL) && (cache >= max->val)) return false;
		return search(node->left, min, node) & search(node->right, node, max);
	}
public:
	bool isValidBST(TreeNode* root)
	{
		return search(root, NULL, NULL);
	}
};

/*
idea: recursive check definition
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isValidBST(NULL) << '\n';
	return 0;
}
#include <vector>
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
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

		 1
		/ \
	   2   5
	  / \   \
	 3   4   6
The flattened tree should look like:
   1
	\
	 2
	  \
	   3
		\
		 4
		  \
		   5
			\
			 6
*/

class Solution
{
private:
	TreeNode *link;
	void search(TreeNode *node)
	{
		if (node == NULL) return;
		TreeNode *left = node->left;
		TreeNode *right = node->right;
		link->left = NULL;
		link->right = node;
		link = node;
		search(left);
		search(right);
	}
public:
	void flatten(TreeNode* root)
	{
		TreeNode result(0);
		result.left = root;
		link = &result;
		search(root);
	}
};

/*
idea: first-order recursive and flatten
complexity: O(N)
*/
int main(void)
{
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution engine;
	engine.flatten(root);
	return 0;
}
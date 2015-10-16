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
https://leetcode.com/problems/invert-binary-tree/

Invert a binary tree.

	 4
   /   \
  2     7
 / \   / \
1   3 6   9
to
	 4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

class Solution
{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == NULL) return NULL;
		TreeNode *cache = root->left;
		root->left = root->right;
		root->right = cache;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

/*
idea: recursive
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.invertTree(NULL) << '\n';
	return 0;
}
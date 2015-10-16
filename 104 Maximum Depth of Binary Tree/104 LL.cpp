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
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.
*/

class Solution
{
public:
	int maxDepth(TreeNode* root)
	{
		if (root == NULL) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

/*
idea: depth first recursive explore
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.maxDepth(NULL) << '\n';
	return 0;
}
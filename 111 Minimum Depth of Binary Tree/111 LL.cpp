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
https://leetcode.com/problems/minimum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.
*/

class Solution
{
private:
	int result;
	void search(TreeNode *root, int depth)
	{
		if (root == NULL) return;
		if ((root->left == NULL) && (root->right == NULL))
		{
			result = min(result, depth);
		}
		search(root->left, depth + 1);
		search(root->right, depth + 1);
	}
public:
	int minDepth(TreeNode* root)
	{
		if (root == NULL) return 0;
		result = 0x7FFFFFFF;
		search(root, 1);
		return result;
	}
};

/*
idea: recursive, attention leaf has both NULL child
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.minDepth(NULL) << '\n';
	return 0;
}
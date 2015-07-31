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
https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree
in which the depth of the two subtrees of every node never differ by more than 1.
*/

class Solution
{
private:
	bool result;
	int search(TreeNode *root, int depth)
	{
		if (!result || (root == NULL)) return depth;
		int left = search(root->left, depth + 1);
		int right = search(root->right, depth + 1);
		result &= ((left + 1) >= right) && (left <= (right + 1));
		return max(left, right);
	}
public:
	bool isBalanced(TreeNode* root)
	{
		result = true;
		search(root, 0);
		return result;
	}
};

/*
idea: height is the max distance of any node to root
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isBalanced(NULL) << '\n';
	return 0;
}
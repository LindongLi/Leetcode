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
https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

	1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
	1
   / \
  2   2
   \   \
   3    3
*/

class Solution
{
private:
	bool check(TreeNode *left, TreeNode *right)
	{
		if ((left == NULL) || (right	== NULL))
		{
			if ((left == NULL) && (right == NULL))
			{
				return true;
			}
			return false;
		}
		if (left->val != right->val) return false;
		return check(left->left, right->right) && check(left->right, right->left);
	}
public:
	bool isSymmetric(TreeNode* root)
	{
		if (root == NULL) return true;
		return check(root->left, root->right);
	}
};

/*
idea: depth first recursive
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isSymmetric(NULL) << '\n';
	return 0;
}
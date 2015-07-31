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
https://leetcode.com/problems/same-tree/

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

class Solution
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if ((p == NULL) || (q == NULL))
		{
			if ((p == NULL) && (q == NULL))
			{
				return true;
			}
			return false;
		}
		if (p->val != q->val) return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

/*
idea: depth first recursive
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isSameTree(NULL, NULL) << '\n';
	return 0;
}
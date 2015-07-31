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
https://leetcode.com/problems/unique-binary-search-trees-ii/

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3
*/

class Solution
{
private:
	vector<TreeNode*> result;
	vector<TreeNode*> source;
	TreeNode *search(int min, int max)
	{

	}
	void copy(TreeNode *src, TreeNode *dst)
	{
		if (src->left != NULL)
		{
			dst->left = new TreeNode(src->left->val);
			copy(src->left, dst->left);
		}
		if (src->right != NULL)
		{
			dst->right = new TreeNode(src->right->val);
			copy(src->right, dst->right);
		}
	}
public:
	vector<TreeNode*> generateTrees(int n)
	{

	}
};
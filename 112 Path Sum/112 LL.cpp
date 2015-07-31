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
https://leetcode.com/problems/path-sum/

Given a binary tree and a sum, determine if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

class Solution
{
private:
	bool result;
	void search(TreeNode *root, int sum)
	{
		if (root == NULL) return;
		if ((root->left == NULL) && (root->right == NULL))
		{
			result |= (sum == root->val);
		}
		else
		{
			sum -= root->val;
			search(root->left, sum);
			search(root->right, sum);
		}
	}
public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		result = false;
		search(root, sum);
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
	cout << engine.hasPathSum(NULL, 0) << '\n';
	return 0;
}
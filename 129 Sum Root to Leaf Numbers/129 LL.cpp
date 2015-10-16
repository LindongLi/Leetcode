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
https://leetcode.com/problems/sum-root-to-leaf-numbers/

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

	1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

class Solution
{
private:
	int result;
	void search(TreeNode *node, int num)
	{
		if (node == NULL) return;
		num = num * 10 + node->val;
		if ((node->left == NULL) && (node->right == NULL))
		{
			result += num;
			return;
		}
		search(node->left, num);
		search(node->right, num);
	}
public:
	int sumNumbers(TreeNode* root)
	{
		result = 0;
		search(root, 0);
		return result;
	}
};

/*
idea: recursive add numbers
complexity: O(N)
*/

int main(void)
{
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution engine;
	cout << engine.sumNumbers(root) << '\n';
	return 0;
}
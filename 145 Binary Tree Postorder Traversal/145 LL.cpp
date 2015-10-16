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
https://leetcode.com/problems/binary-tree-postorder-traversal/

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
	\
	 2
	/
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution
{
private:
	vector<int> result;
	vector<TreeNode*> trace;
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		while (!trace.empty())
		{
			root = trace.back();
			if (root != NULL)
			{
				trace.push_back()
			}
		}
	}
};
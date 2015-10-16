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
https://leetcode.com/problems/binary-tree-preorder-traversal/

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
	\
	 2
	/
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution
{
private:
	vector<int> result;
	vector<TreeNode*> trace;
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		trace.push_back(root);
		while (!trace.empty())
		{
			root = trace.back();
			trace.pop_back();
			if (root != NULL)
			{
				result.push_back(root->val);
				trace.push_back(root->right);
				trace.push_back(root->left);
			}
		}
		return result;
	}
};

/*
idea:
complexity: O(N)
*/
int main(void)
{
	Solution engine;
	cout << engine.preorderTraversal(NULL).size() << '\n';
	return 0;
}
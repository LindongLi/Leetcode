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
https://leetcode.com/problems/binary-tree-inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;
		vector<TreeNode*> trace;
		if (root != NULL)
		{
			trace.push_back(root);
			while (trace.back()->left != NULL)
			{
				trace.push_back(trace.back()->left);
			}
		}
		while (trace.size() != 0)
		{
			TreeNode *cache = trace.back();
			result.push_back(cache->val);
			if ((cache = cache->right) != NULL)
			{
				trace.back() = cache;
				while ((cache = cache->left) != NULL)
				{
					trace.push_back(cache);
				}
			}
			else trace.pop_back();
		}
		return result;
	}
};

/*
idea: search all left branch, visit self then right branch
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.inorderTraversal(new TreeNode(0)).size() << '\n';
	return 0;
}
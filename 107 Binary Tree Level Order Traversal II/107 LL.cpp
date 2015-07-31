#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
	3
   / \
  9  20
	/  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

class Solution
{
private:
	vector<vector<int> > result;
	void search(TreeNode *root, int depth)
	{
		if (root == NULL) return;
		if (result.size() < depth)
		{
			result.resize(depth);
		}
		result[depth - 1].push_back(root->val);
		search(root->left, depth + 1);
		search(root->right, depth + 1);
	}
public:
	vector<vector<int> > levelOrderBottom(TreeNode* root)
	{
		search(root, 1);
		reverse(result.begin(), result.end());
		return result;
	}
};

/*
idea: depth first recursive then reverse
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.levelOrderBottom(NULL).size() << '\n';
	return 0;
}
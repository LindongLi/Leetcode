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
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
	3
   / \
  9  20
	/  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
	vector<vector<int> > zigzagLevelOrder(TreeNode* root)
	{
		search(root, 1);
		for (int i = 1; i < result.size(); i += 2)
		{
			reverse(result[i].begin(), result[i].end());
		}
		return result;
	}
};

/*
idea: depth first recursive, then reverse odd lines
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.zigzagLevelOrder(NULL).size() << '\n';
	return 0;
}
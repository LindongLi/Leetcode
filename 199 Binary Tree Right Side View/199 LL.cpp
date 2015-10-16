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
https://leetcode.com/problems/binary-tree-right-side-view/

Given a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

class Solution
{
private:
	vector<int> result;
	void search(TreeNode *node, int depth)
	{
		if (node == NULL) return;
		if (result.size() < depth)
		{
			result.push_back(node->val);
		}
		else
		{
			result[depth - 1] = node->val;
		}
		search(node->left, depth + 1);
		search(node->right, depth + 1);
	}
public:
	vector<int> rightSideView(TreeNode* root)
	{
		search(root, 1);
		return result;
	}
};

/*
idea: depth first search
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.rightSideView(NULL).size() << '\n';
	return 0;
}
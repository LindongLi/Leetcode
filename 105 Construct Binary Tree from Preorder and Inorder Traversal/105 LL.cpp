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
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution
{
private:
	vector<int>::iterator pre_root;
	vector<int>::iterator inorder_data;
	void buildRoot(TreeNode *tree, int root, int imin, int imax)
	{
		tree->val = pre_root[root];
		for (int i = imin; i <= imax; ++i)
		{
			if (tree->val == inorder_data[i])	// match root inorder position
			{
				if (i != imin)	// left tree exists
				{
					tree->left = new TreeNode(0);
					buildRoot(tree->left, root + 1, imin, i - 1);
				}
				if ((i + 1) <= imax)	// right tree exists
				{
					tree->right = new TreeNode(0);
					buildRoot(tree->right, root + i + 1 - imin, i + 1, imax);
				}
				break;
			}
		}
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		TreeNode *result = NULL;
		if (inorder.size() != 0)
		{
			pre_root = preorder.begin();
			inorder_data = inorder.begin();
			result = new TreeNode(0);
			buildRoot(result, 0, 0, inorder.size() - 1);
		}
		return result;
	}
};

/*
idea: divide preorder to left & right part using inorder, then d-q solve subproblems
complexity: O(N)
*/

int main(void)
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(3);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(6);
	vector<int> inorder;
	inorder.push_back(3);
	inorder.push_back(2);
	inorder.push_back(1);
	inorder.push_back(5);
	inorder.push_back(4);
	inorder.push_back(6);
	Solution engine;
	engine.buildTree(preorder, inorder);
	return 0;
}
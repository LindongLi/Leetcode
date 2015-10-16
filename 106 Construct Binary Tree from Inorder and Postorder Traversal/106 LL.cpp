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
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution
{
private:
	vector<int>::iterator post_root;
	vector<int>::iterator inorder_data;
	void buildRoot(TreeNode *tree, int root, int imin, int imax)
	{
		tree->val = post_root[root];
		for (int i = imin; i <= imax; ++i)
		{
			if (tree->val == inorder_data[i])	// match root inorder position
			{
				if (i != imin)	// left tree exists
				{
					tree->left = new TreeNode(0);
					buildRoot(tree->left, root + i - 1 - imax, imin, i - 1);
				}
				if ((i + 1) <= imax)	// right tree exists
				{
					tree->right = new TreeNode(0);
					buildRoot(tree->right, root - 1, i + 1, imax);
				}
				break;
			}
		}
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		TreeNode *result = NULL;
		if (inorder.size() != 0)
		{
			post_root = postorder.begin();
			inorder_data = inorder.begin();
			result = new TreeNode(0);
			buildRoot(result, postorder.size() - 1, 0, inorder.size() - 1);
		}
		return result;
	}
};

/*
idea: divide postorder to left & right part using inorder, then d-q solve subproblems
complexity: O(N)
*/

int main(void)
{
	vector<int> inorder;
	inorder.push_back(3);
	inorder.push_back(2);
	inorder.push_back(1);
	inorder.push_back(5);
	inorder.push_back(4);
	inorder.push_back(6);
	vector<int> postorder;
	postorder.push_back(3);
	postorder.push_back(2);
	postorder.push_back(5);
	postorder.push_back(6);
	postorder.push_back(4);
	postorder.push_back(1);
	Solution engine;
	engine.buildTree(inorder, postorder);
	return 0;
}
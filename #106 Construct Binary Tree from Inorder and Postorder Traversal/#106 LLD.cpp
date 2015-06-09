#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
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
	vector<int>* pinorder;
	vector<int>* ppostorder;
	void buildRoot(int pend, int istt, int iend, TreeNode* tree)
	{
		int i;	// index on inorder vector
		for (i = istt; i < iend; i++)
		{
			if ((*pinorder)[i] == tree->val)
			{
				if (i != istt)
				{
					tree->left = new TreeNode((*ppostorder)[pend + i - iend - 1]);
					buildRoot(pend + i - iend, istt, i, tree->left);
				}
				break;
			}
		}
		i++;	// skip root: tree->val or (*ppostorder)[i]
		if (i != iend)
		{
			tree->right = new TreeNode((*ppostorder)[pend - 2]);
			buildRoot(pend - 1, i, iend, tree->right);
		}
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		TreeNode *result = NULL;
		if (postorder.size() != 0)
		{
			pinorder = &inorder;
			ppostorder = &postorder;
			result = new TreeNode(postorder[postorder.size() - 1]);
			buildRoot(postorder.size(), 0, inorder.size(), result);
		}
		return result;
	}
};

/*
idea: divide postorder to left & right part using inorder, then d-q solve subproblems
complexity: O(N)
*/

void Print(TreeNode *t)
{
	if (t->left != NULL) Print(t->left);
	cout << t->val;
	if (t->right != NULL) Print(t->right);
}
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
	Print(engine.buildTree(inorder, postorder));
	return 0;
}
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
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution
{
private:
	vector<int>* ppreorder;
	vector<int>* pinorder;
	void buildRoot(int pstt, int istt, int iend, TreeNode* tree)
	{
		int i;	// index on inorder vector
		for (i = istt; i < iend; i++)
		{
			if ((*pinorder)[i] == tree->val)
			{
				if (i != istt)
				{
					tree->left = new TreeNode((*ppreorder)[pstt + 1]);
					buildRoot(pstt + 1, istt, i, tree->left);
				}
				break;
			}
		}
		i++;	// skip root: tree->val or (*ppreorder)[pstt]
		if (i != iend)
		{
			tree->right = new TreeNode((*ppreorder)[pstt + i - istt]);
			buildRoot(pstt + i - istt, i, iend, tree->right);
		}
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		TreeNode *result = NULL;
		if (preorder.size() != 0)
		{
			ppreorder = &preorder;
			pinorder = &inorder;
			result = new TreeNode(preorder[0]);
			buildRoot(0, 0, inorder.size(), result);
		}
		return result;
	}
};

/*
idea: divide preorder to left & right part using inorder, then d-q solve subproblems
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
	Print(engine.buildTree(preorder, inorder));
	return 0;
}
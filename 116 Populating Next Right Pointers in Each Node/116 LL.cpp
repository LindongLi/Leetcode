#include <iostream>
using namespace std;
struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Given a binary tree, Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree
(ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
		 1
	   /  \
	  2    3
	 / \  / \
	4  5  6  7
After calling your function, the tree should look like:
		 1 -> NULL
	   /  \
	  2 -> 3 -> NULL
	 / \  / \
	4->5->6->7 -> NULL
*/

class Solution
{
private:
	void search(TreeLinkNode *linkfrom, TreeLinkNode *node)
	{
		if (node == NULL) return;
		if (linkfrom != NULL)
		{
			linkfrom->next = node;
			search(linkfrom->right, node->left);
		}
		else search(NULL, node->left);
		search(node->left, node->right);
	}
public:
	void connect(TreeLinkNode *root)
	{
		search(NULL, root);
	}
};

/*
idea: recursive bind every siblings
complexity: O(N)
*/
int main(void)
{
	Solution engine;
	engine.connect(NULL);
	return 0;
}
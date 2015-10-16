#include <iostream>
using namespace std;
struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Follow up for problem "Populating Next Right Pointers in Each Node (#116)".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
		 1
	   /  \
	  2    3
	 / \    \
	4   5    7
After calling your function, the tree should look like:
		 1 -> NULL
	   /  \
	  2 -> 3 -> NULL
	 / \    \
	4-> 5 -> 7 -> NULL
*/

class Solution
{
private:
	void search(TreeLinkNode *layer)
	{
		if (layer == NULL) return;
		TreeLinkNode answer(0);
		TreeLinkNode *slide = &answer;
		while (layer != NULL)
		{
			if (layer->left != NULL)
			{
				slide->next = layer->left;
				slide = slide->next;
			}
			if (layer->right != NULL)
			{
				slide->next = layer->right;
				slide = slide->next;
			}
			layer = layer->next;
		}
		search(answer.next);
	}
public:
	void connect(TreeLinkNode *root)
	{
		search(root);
	}
};

/*
idea: process sibling layer by layer
complexity: O(N)
*/
int main(void)
{
	Solution engine;
	engine.connect(NULL);
	return 0;
}
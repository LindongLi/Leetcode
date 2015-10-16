#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/delete-node-in-a-linked-list/

Write a function to delete a node (except the tail) in a singly linked list,
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
the linked list should become 1 -> 2 -> 4 after calling your function.
*/

class Solution
{
public:
	void deleteNode(ListNode* node)
	{
		ListNode *slide = (node != NULL) ? node->next : NULL;
		if (slide == NULL) return;
		while (slide->next != NULL)
		{
			node->val = slide->val;
			node = slide;
			slide = slide->next;
		}
		node->val = slide->val;
		node->next = NULL;
	}
};

/*
idea: move link one by one
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	engine.deleteNode(NULL);
	return 0;
}
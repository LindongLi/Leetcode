#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
*/

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (head == NULL) return NULL;
		ListNode superhead(0);
		superhead.next = head;
		int mempos = 0;
		ListNode *remember[n + 1];
		ListNode *slide = &superhead;
		while (slide != NULL)
		{
			remember[mempos] = slide;
			if (++mempos > n) mempos = 0;
			slide = slide->next;
		}
		remember[mempos]->next = remember[mempos]->next->next;
		return superhead.next;
	}
};

/*
idea: using queue to remember last n + 1 nodes
complexity: O(N)
*/

int main(void)
{
	ListNode *head = NULL;
	Solution engine;
	cout << engine.removeNthFromEnd(head, 0) << '\n';
	return 0;
}
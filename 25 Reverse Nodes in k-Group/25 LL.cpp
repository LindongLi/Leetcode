#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

class Solution
{
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (k <= 1) return head;
		ListNode result(0);
		result.next = head;
		ListNode *slide = &result;
		while (slide->next != NULL)
		{
			ListNode *lasttail = slide;
			ListNode *head = slide->next;
			for (int i = 0; i < k; ++i)
			{
				slide = slide->next;
				if (slide == NULL) return result.next;
			}
			lasttail->next = slide;
			lasttail = head;
			ListNode *linkpre = slide->next;
			while (linkpre != slide)
			{
				ListNode *cache = head->next;
				head->next = linkpre;
				linkpre = head;
				head = cache;
			}
			slide = lasttail;
		}
		return result.next;
	}
};

/*
idea: reverse using stack
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.reverseKGroup(NULL, 2) << '\n';
	return 0;
}
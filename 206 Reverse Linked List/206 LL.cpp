#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.
A linked list can be reversed either iteratively or recursively.
*/

class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL) return NULL;
		ListNode *next = head->next;
		head->next = NULL;
		while (next != NULL)
		{
			ListNode *nnext = next->next;
			next->next = head;
			head = next;
			next = nnext;
		}
		return head;
	}
};

/*
idea: reverse iteratively
complexity: O(N)
*/

int main(void)
{
	ListNode *head = NULL;
	Solution engine;
	cout << engine.reverseList(head) << '\n';
	return 0;
}
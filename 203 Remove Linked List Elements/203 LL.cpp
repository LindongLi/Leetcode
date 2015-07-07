#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		while ((head != NULL) && (head->val == val))
		{
			head = head->next;
		}
		if (head == NULL) return NULL;
		ListNode *shift = head;
		while (shift->next != NULL)
		{
			if (shift->next->val == val)
			{
				shift->next = shift->next->next;
			}
			else shift = shift->next;
		}
		return head;
	}
};

/*
idea: remove iteratively
complexity: O(N)
*/

int main(void)
{
	ListNode *head = NULL;
	Solution engine;
	cout << engine.removeElements(head, 0) << '\n';
	return 0;
}
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		int total = 1;
		ListNode *slide = head;
		if (k == 0) return head;
		if (head == NULL) return NULL;
		while (slide->next != NULL)
		{
			slide = slide->next;
			++total;
		}
		slide->next = head;	// make a circle
		int tail = total - k % total;
		for (int i = 1; i < tail; ++i)
		{
			head = head->next;
		}
		slide = head->next;
		head->next = NULL;
		return slide;
	}
};

/*
idea: slide twice, first get link length
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.rotateRight(NULL, 4) << '\n';
	return 0;
}
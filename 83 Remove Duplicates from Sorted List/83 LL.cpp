#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == NULL) return NULL;
		ListNode *slide = head;
		while (slide->next != NULL)
		{
			if (slide->val == slide->next->val)
			{
				slide->next = slide->next->next;
			}
			else slide = slide->next;
		}
		return head;
	}
};

/*
idea: iterative delete
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.deleteDuplicates(NULL) << '\n';
	return 0;
}
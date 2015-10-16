#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
*/

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode result(0);
		ListNode *slide = &result;
		while ((l1 != NULL) && (l2 != NULL))
		{
			if (l1->val < l2->val)
			{
				slide->next = l1;
				l1 = l1->next;
			}
			else
			{
				slide->next = l2;
				l2 = l2->next;
			}
			slide = slide->next;
		}
		slide->next = (l1 == NULL) ? l2 : l1;
		return result.next;
	}
};

/*
idea: independent ListNode as start
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.mergeTwoLists(NULL, NULL) << '\n';
	return 0;
}
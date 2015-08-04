#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
*/

class Solution
{
public:
	ListNode* insertionSortList(ListNode* head)
	{
		ListNode result(0);
		while (head != NULL)
		{
			ListNode *slide = &result;
			while ((slide->next != NULL) && (slide->next->val <= head->val))
			{
				slide = slide->next;
			}
			ListNode *next = head->next;
			head->next = slide->next;
			slide->next = head;
			head = next;
		}
		return result.next;
	}
};

/*
idea: insertion sort
complexity: Time O(N^2)
*/

int main(void)
{
	ListNode *head = new ListNode(1);
	Solution engine;
	cout << engine.insertionSortList(head) << '\n';
	return 0;
}
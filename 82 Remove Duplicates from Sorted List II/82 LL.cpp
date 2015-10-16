#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode result(0);
		result.next = head;
		ListNode *last = &result;
		while (head != NULL)
		{
			int target = head->val;
			int count = 0;
			do
			{
				++count;
				head = head->next;
			}
			while ((head != NULL) && (target == head->val));
			if (count == 1)	// no duplicate
			{
				last = last->next;
			}
			else last->next = head;
		}
		return result.next;
	}
};

/*
idea: count duplicate for every value
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.deleteDuplicates(new ListNode(0)) << '\n';
	return 0;
}
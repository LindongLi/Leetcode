#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/partition-list/

Given a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

class Solution
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		ListNode min(0), max(0);
		ListNode *Pmin = &min, *Pmax = &max;
		while (head != NULL)
		{
			if (head->val < x)
			{
				Pmin->next = head;
				Pmin = head;
				head = head->next;
				Pmin->next = NULL;
			}
			else
			{
				Pmax->next = head;
				Pmax = head;
				head = head->next;
				Pmax->next = NULL;
			}
		}
		Pmin->next = max.next;
		return min.next;
	}
};

/*
idea: split in two lists and merge
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.partition(new ListNode(0), 1) << '\n';
	return 0;
}
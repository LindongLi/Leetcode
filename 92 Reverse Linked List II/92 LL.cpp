#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

class Solution
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		ListNode result(0);
		result.next = head;
		ListNode *slide = &result;
		int i = 0;
		for (; i < m; ++i)
		{
			head = slide;
			slide = slide->next;
		}
		ListNode *last = NULL;
		for (; i <= n; ++i)
		{
			ListNode *cache = slide->next;
			slide->next = last;
			last = slide;
			slide = cache;
		}
		head->next->next = slide;
		head->next = last;
		return result.next;
	}
};

/*
idea: two pointer reverse
complexity: O(N)
*/
int main(void)
{
	ListNode *head;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution engine;
	cout << engine.reverseBetween(head, 2, 5) << '\n';
	return 0;
}
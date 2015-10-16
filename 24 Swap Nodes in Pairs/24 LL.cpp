#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space.
You may not modify the values in the list, only nodes itself can be changed.
*/

class Solution
{
public:
	ListNode* swapPairs(ListNode* head)
	{
		ListNode result(0);
		result.next = head;
		ListNode *slide = &result;
		while (true)
		{
			ListNode *first = slide->next;
			if (first == NULL) break;
			ListNode *second = first->next;
			if (second == NULL) break;
			first->next = second->next;
			second->next = first;
			slide->next = second;
			slide = first;
		}
		return result.next;
	}
};

/*
idea: two additional pointers
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.swapPairs(NULL) << '\n';
	return 0;
}
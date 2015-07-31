#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8
*/

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *now = new ListNode(0);
		ListNode *result = now;
		int carry = 0;
		while (true)
		{
			bool looping = (carry != 0);
			if (l1 != NULL)
			{
				looping = true;
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				looping = true;
				carry += l2->val;
				l2 = l2->next;
			}
			if (!looping) break;
			if (carry >= 10)
			{
				now->next = new ListNode(carry - 10);
				carry = 1;
			}
			else
			{
				now->next = new ListNode(carry);
				carry = 0;
			}
			now = now->next;
		}
		if (result->next != NULL)
		{
			return result->next;
		}
		else return result;	// handle empty input
	}
};

/*
idea: simulate hand calculating
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	engine.addTwoNumbers(NULL, NULL);
	return 0;
}
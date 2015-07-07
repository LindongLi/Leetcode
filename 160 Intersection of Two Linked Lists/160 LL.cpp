#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/intersection-of-two-linked-lists/

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:			a1 → a2
				   ↘
					c1 → c2 → c3
				   ↗
B:		b1 → b2 → b3
begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if ((headA == NULL) || (headB == NULL)) return NULL;
		ListNode *glideA = headA, *glideB = headB;
		bool secondpass[2] = {false, false};
		while (glideA != glideB)
		{
			glideA = glideA->next;
			glideB = glideB->next;
			if (glideA == NULL)
			{
				if (secondpass[0]) return NULL;
				secondpass[0] = true;
				glideA = headB;
			}
			if (glideB == NULL)
			{
				if (secondpass[1]) return NULL;
				secondpass[1] = true;
				glideB = headA;
			}
		}
		return glideA;
	}
};

/*
idea: cross gliding ensure two pointer pass same length
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.getIntersectionNode(NULL, NULL) << '\n';
	return 0;
}
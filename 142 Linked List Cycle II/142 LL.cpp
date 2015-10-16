#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins.
If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		ListNode *slow = head, *fast = head;
		while ((slow != NULL) && (fast != NULL))
		{
			slow = slow->next;
			fast = (fast->next != NULL) ? fast->next->next : NULL;
			if (slow == fast)
			{
				if (slow == NULL) break;
				while (slow != head)
				{
					slow = slow->next;
					head = head->next;
				}
				return slow;
			}
		}
		return NULL;
	}
};

/*
idea: fast slow chasing pointers
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.detectCycle(NULL) << '\n';
	return 0;
}
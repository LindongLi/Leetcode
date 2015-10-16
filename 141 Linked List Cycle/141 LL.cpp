#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/linked-list-cycle/

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

class Solution
{
public:
	bool hasCycle(ListNode *head)
	{
		ListNode *fast = head;
		while ((head != NULL) && (fast != NULL))
		{
			head = head->next;
			fast = (fast->next != NULL) ? fast->next->next : NULL;
			if (head == fast) return (head != NULL);
		}
		return false;
	}
};

/*
idea: fast slow chasing pointers
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.hasCycle(NULL) << '\n';
	return 0;
}
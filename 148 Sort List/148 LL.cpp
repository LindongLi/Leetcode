#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/sort-list/

Sort a linked list in O(n log n) time using constant space complexity.
*/

class Solution
{
private:
	static ListNode* merge(ListNode *head, ListNode* l1, ListNode* l2)
	{
		while ((l1 != NULL) && (l2 != NULL))
		{
			if (l1->val < l2->val)
			{
				head->next = l1;
				l1 = l1->next;
			}
			else
			{
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		head->next = (l1 == NULL) ? l2 : l1;
		while (head->next != NULL)
		{
			head = head->next;
		}
		return head;
	}
	static ListNode *isolate(ListNode *base, int go)
	{
		while ((--go > 0) && (base->next != NULL))
		{
			base = base->next;
		}
		return base;
	}
public:
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL) return NULL;
		ListNode result(0);
		result.next = head;
		int length = 1;
		while (true)
		{
			head = result;
			bool exit = true;
			ListNode *left = head->next, *cache;
			while (left != NULL)
			{
				cache = isolate(left, length);
				ListNode right = cache->next;
				cache->next = NULL;
				if (right == NULL) break;
				cache = isolate(right, length);
				ListNode *nleft = cache->next;
				cache->next = NULL;
				head = merge(head, left, right);
				left = nleft;
				exit = false;
			}
			length <<= 1;
			if (exit) break;
		}
		return result.next;
	}
};

/*
idea: merge sort, careful pointer operations
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
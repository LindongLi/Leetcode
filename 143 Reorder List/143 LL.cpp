#include <vector>
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/reorder-list/

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

class Solution
{
private:
	vector<ListNode*> trace;
public:
	void reorderList(ListNode* head)
	{
		if ((head != NULL) && (head->next != NULL))
		{
			ListNode *slide = head;
			while (slide != NULL)
			{
				trace.push_back(slide);
				slide = slide->next;
			}
			slide = head;
			while ((slide != NULL) && (slide->next != NULL))
			{
				ListNode *cache = trace.back();
				trace.pop_back();
				trace.back()->next = NULL;
				cache->next = slide->next;
				slide->next = cache;
				slide = cache->next;
			}
		}
	}
};

/*
idea: using vector as stack to reverse
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	engine.reorderList(NULL);
	return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
https://leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

class Solution
{
private:
	vector<ListNode*> heap;
	static bool compare(ListNode *a, ListNode *b)
	{
		return (a->val > b->val);
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode result(0);
		vector<ListNode*>::iterator data = lists.begin();
		for (; data != lists.end(); ++data)
		{
			if (data[0] != NULL) heap.push_back(data[0]);
		}
		make_heap(heap.begin(), heap.end(), compare);
		ListNode *slide = &result;
		while (heap.size() != 0)
		{
			pop_heap(heap.begin(), heap.end(), compare);
			slide->next = heap.back();
			slide = slide->next;
			if (slide->next != NULL)
			{
				heap.back() = slide->next;
				push_heap(heap.begin(), heap.end(), compare);
			}
			else heap.pop_back();
		}
		return result.next;
	}
};

/*
idea: using min heap tracing element
complexity: Time O(NlogN)
*/

int main(void)
{
	vector<ListNode*> lists;
	lists.push_back(new ListNode(2));
	lists.push_back(new ListNode(1));
	lists.push_back(NULL);
	Solution engine;
	cout << engine.mergeKLists(lists) << '\n';
	return 0;
}
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
	vector<ListNode*> data;
	bool pull_up(int pos = 1)
	{
		if (pos > data.size())
		{
			return false;
		}
		int child = pos << 1, i = pos;
		if (pull_up(child) && (data[i - 1]->val > data[child - 1]->val))
		{
			i = child;
		}
		if (pull_up(child + 1) && (data[i - 1]->val > data[child]->val))
		{
			i = child + 1;
		}
		if (i != pos)
		{
			swap(data[pos - 1], data[i - 1]);
			push_down(i);
		}
		return true;
	}
	void push_down(int pos = 1)
	{
		int child = pos << 1, i = pos;
		if ((child <= data.size()) && (data[i - 1]->val > data[child - 1]->val))
		{
			i = child;
		}
		if ((child < data.size()) && (data[i - 1]->val > data[child]->val))
		{
			i = child + 1;
		}
		if (i != pos)
		{
			swap(data[pos - 1], data[i - 1]);
			push_down(i);
		}
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode result(0);
		vector<ListNode*>::iterator it = lists.begin();
		for (; it != lists.end(); ++it)
		{
			if (it[0] != NULL)
			{
				data.push_back(it[0]);
			}
		}
		Solution::pull_up();
		ListNode *slide = &result;
		while (data.size() != 0)
		{
			slide->next = data[0];
			slide = slide->next;
			if (slide->next != NULL)
			{
				data[0] = slide->next;
			}
			else
			{
				data[0] = data.back();
				data.pop_back();
			}
			Solution::push_down();
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
	lists.push_back(new ListNode(3));
	lists.push_back(new ListNode(2));
	Solution engine;
	cout << engine.mergeKLists(lists)->val << '\n';
	return 0;
}
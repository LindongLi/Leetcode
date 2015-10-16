#include <vector>
#include <iostream>
using namespace std;
struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/*
https://leetcode.com/problems/copy-list-with-random-pointer/

A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.
*/

class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (head == NULL) return NULL;
		vector<RandomListNode *> order;
		RandomListNode *slide = head;
		while (slide != NULL)
		{
			order.push_back(slide);
			RandomListNode *next = slide->next;
			slide->next = new RandomListNode(slide->label);
			(slide->next)->random = slide->random;
			slide = next;
		}
		RandomListNode *result = order[0]->next;
		vector<RandomListNode *>::iterator it = order.begin();
		for (; it != order.end(); ++it)
		{
			if ((it[0]->next)->random != NULL)
			{
				(it[0]->next)->random = ((it[0]->next)->random)->next;
			}
		}
		it = order.begin() + 1;
		for (; it != order.end(); ++it)
		{
			(it[-1]->next)->next = it[0]->next;
			it[-1]->next = it[0];
		}
		order.back()->next = NULL;
		return result;
	}
};

/*
idea: fix random pointer then link next
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.copyRandomList(NULL) << '\n';
	return 0;
}
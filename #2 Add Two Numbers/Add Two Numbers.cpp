#include <iostream>
using namespace std;
struct ListNode {
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
		int carryon = 0;
		ListNode *ans = new ListNode(0), *rtn = ans;
		while(true)
		{
			bool looping = (carryon != 0);
			if(l1 != NULL)
			{
				looping = true;
				carryon += l1->val;
				l1 = l1->next;
			}
			if(l2 != NULL)
			{
				looping = true;
				carryon += l2->val;
				l2 = l2->next;
			}
			if(!looping) break;
			ans->next = new ListNode(carryon % 10);
			carryon = carryon / 10;
			ans = ans->next;
		}
		return (rtn->next != NULL) ? rtn->next : rtn;
	}
};

/*
test
*/
void Print(ListNode *l)
{
	cout << l->val;
	if(l->next != NULL)
	{
		cout << '\t';
		Print(l->next);
	}
	else cout << '\n';
}
int main(void)
{
	ListNode *l1 = NULL;
	ListNode *l2 = NULL;
	Solution engine;
	Print(engine.addTwoNumbers(l1, l2));
	return 0;
}
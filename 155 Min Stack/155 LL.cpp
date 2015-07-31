#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack
{
private:
	vector<int> minlist;
	vector<int> list;	// data list
public:
	void push(int x)
	{
		if ((list.size() == 0) || (minlist.back() >= x))
		{
			minlist.push_back(x);
		}
		list.push_back(x);
	}
	void pop()
	{
		if (list.size() == 0) return;
		if (list.back() == minlist.back())
		{
			minlist.pop_back();
		}
		list.pop_back();
	}
	int top()
	{
		if (list.size() == 0) return 0;
		return list.back();
	}
	int getMin()
	{
		if (list.size() == 0) return 0;
		return minlist.back();
	}
};

/*
idea: second vector for minimal element
complexity: O(N)
*/

int main(void)
{
	MinStack engine;
	engine.push(-2);
	engine.push(0);
	engine.push(-1);
	cout << engine.getMin() << '\n';
	cout << engine.top() << '\n';
	engine.pop();
	cout << engine.getMin() << '\n';
	return 0;
}
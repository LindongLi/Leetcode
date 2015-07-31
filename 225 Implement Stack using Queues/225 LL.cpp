#include <queue>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/implement-stack-using-queues/

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back,
peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively.
You may simulate a queue by using a list or deque (double-ended queue),
as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example,
no pop or top operations will be called on an empty stack).
*/

class Stack
{
private:
	queue<int> data;
public:
	void push(int x)	// Push element x onto stack.
	{
		queue<int> backdata;
		while (!data.empty())
		{
			backdata.push(data.front());
			data.pop();
		}
		data.push(x);	// pushed
		while (!backdata.empty())
		{
			data.push(backdata.front());
			backdata.pop();
		}
	}
	void pop()	// Removes the element on top of the stack.
	{
		if (!data.empty())
		{
			data.pop();
		}
	}
	int top()	// Get the top element.
	{
		return data.empty() ? 0 : data.front();
	}
	bool empty()	// Return whether the stack is empty.
	{
		return data.empty();
	}
};

/*
idea: pushed element move to front of queue
complexity: O(N)
*/

int main(void)
{
	Stack engine;
	engine.push(1);
	engine.push(2);
	cout << engine.top() << '\n';
	return 0;
}
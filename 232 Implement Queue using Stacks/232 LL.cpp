#include <stack>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/implement-queue-using-stacks/

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top,
peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively.
You may simulate a stack by using a list or deque (double-ended queue),
as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example,
no pop or peek operations will be called on an empty queue).
*/

class Queue
{
private:
	stack<int> data;
public:
	void push(int x)	// Push element x to the back of queue.
	{
		stack<int> backdata;
		while (!data.empty())
		{
			backdata.push(data.top());
			data.pop();
		}
		data.push(x);	// pushed
		while (!backdata.empty())
		{
			data.push(backdata.top());
			backdata.pop();
		}
	}
	void pop(void)	// Removes the element from in front of queue.
	{
		if (!data.empty())
		{
			data.pop();
		}
	}
	int peek(void)	// Get the front element.
	{
		return data.empty() ? 0 : data.top();
	}
	bool empty(void)	// Return whether the queue is empty.
	{
		return data.empty();
	}
};

/*
idea: pushed element move to end of stack
complexity: O(N)
*/

int main(void)
{
	Queue engine;
	engine.push(1);
	engine.push(2);
	cout << engine.peek() << '\n';
	return 0;
}
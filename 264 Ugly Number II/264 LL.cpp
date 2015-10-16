#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/ugly-number-ii/

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

class Solution
{
public:
	int nthUglyNumber(int n)
	{
		vector<int> trace(1, 1);
		int pos[3] = {0, 0, 0};
		int val[3] = {2, 3, 5};
		while (trace.size() < n)
		{
			int todo = min(val[0], min(val[1], val[2]));
			trace.push_back(todo);
			// attention same number case
			if (todo == val[0])
			{
				val[0] = trace[++pos[0]] * 2;
			}
			if (todo == val[1])
			{
				val[1] = trace[++pos[1]] * 3;
			}
			if (todo == val[2])
			{
				val[2] = trace[++pos[2]] * 5;
			}
		}
		return trace.back();
	}
};

/*
idea: three generators
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.nthUglyNumber(10) << '\n';
	return 0;
}
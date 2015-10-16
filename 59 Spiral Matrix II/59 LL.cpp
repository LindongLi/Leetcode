#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/spiral-matrix-ii/

Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution
{
public:
	vector<vector<int> > generateMatrix(int n)
	{
		// cool initial method
		vector<vector<int> > result(n, vector<int>(n));
		int posm = 0, posn = -1;
		int step = n, cnt = 0;
		while (1)
		{
			for (int i = 0; i < step; ++i)
			{
				result[posm][++posn] = ++cnt;
			}
			if (--step <= 0) break;
			for (int i = 0; i < step; ++i)
			{
				result[++posm][posn] = ++cnt;
			}
			for (int i = 0; i < step; ++i)
			{
				result[posm][--posn] = ++cnt;
			}
			if (--step <= 0) break;
			for (int i = 0; i < step; ++i)
			{
				result[--posm][posn] = ++cnt;
			}
		}
		return result;
	}
};

/*
idea: route calculating
complexity: Time O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.generateMatrix(3).size() << '\n';
	return 0;
}
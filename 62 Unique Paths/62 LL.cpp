#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		--m;
		--n;
		int c = min(m , n);
		if (c < 0) return 0;
		long long int result = 1;
		for (int i = 1; i <= c; ++i)
		{
			// attention overflow may occur
			result = result * (m + n + 1 - i) / i;
		}
		return (int)result;
	}
};

/*
idea: min(m, n) combined (m + n)
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.uniquePaths(3, 7) << '\n';
	return 0;
}
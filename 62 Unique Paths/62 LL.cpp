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
		int c = min(m - 1 , n - 1);
		long long int result = (c < 0) ? 0 : 1;
		for (int i = 0; i < c; ++i)
		{
			// attention overflow may occur
			result = result * (m + n - 2 - i) / (i + 1);
		}
		return (int)result;
	}
};

/*
idea: pick (m - 1) right moves from (m - 1 + n - 1) total moves
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.uniquePaths(3, 7) << '\n';
	return 0;
}
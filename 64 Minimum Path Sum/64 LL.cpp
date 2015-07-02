#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution
{
public:
	int minPathSum(vector<vector<int> >& grid)
	{
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;
		// process first row
		for (int col = 1; col < n; ++col)
		{
			grid[0][col] += grid[0][col - 1];
		}
		for (int row = 1; row < m; ++row)
		{
			grid[row][0] += grid[row - 1][0];
			for (int col = 1; col < n; ++col)
			{
				grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
			}
		}
		return grid[m - 1][n - 1];
	}
};

/*
idea: two-way dynamic programing
complexity: Time O(logN)
*/

int main(void)
{
	vector<vector<int> > grid;
	vector<int> nums(2);
	nums[0] = 1;
	nums[1] = 2;
	grid.push_back(nums);
	nums[0] = 1;
	nums[1] = 1;
	grid.push_back(nums);
	Solution engine;
	cout << engine.minPathSum(grid) << '\n';
	return 0;
}
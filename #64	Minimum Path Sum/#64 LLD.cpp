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
		int n = grid.size();
		if (n == 0) return 0;
		int m = grid[0].size();
		if (m == 0) return 0;
		// process first row
		for (int c = 1; c < m; c++)
		{
			grid[0][c] += grid[0][c - 1];
		}
		for (int r = 1; r < n; r++)
		{
			grid[r][0] += grid[r - 1][0];
			for (int c = 1; c < m; c++)
			{
				grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
			}
		}
		return grid[n - 1][m - 1];
	}
};

/*
idea: two-way dynamic programing
complexity: Time O(logN)
*/

int main(void)
{
	vector<vector<int> > grid;
	vector<int> nums;
	nums.resize(2);
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
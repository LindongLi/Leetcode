#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/

class Solution
{
private:
	int cols, rows;
	bool modify(vector<vector<char> > &grid, int col, int row)
	{
		if (grid[col][row] == '1')
		{
			grid[col][row] = '2';
			if (col > 0)
			{
				modify(grid, col - 1, row);
			}
			if (col < (cols - 1))
			{
				modify(grid, col + 1, row);
			}
			if (row > 0)
			{
				modify(grid, col, row - 1);
			}
			if (row < (rows - 1))
			{
				modify(grid, col, row + 1);
			}
			return true;
		}
		return false;
	}
public:
	int numIslands(vector<vector<char> >& grid)
	{
		int result = 0;
		cols = grid.size();
		if (cols == 0) return 0;
		rows = grid[0].size();
		if (rows == 0) return 0;
		for (int i = 0; i < cols; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				if (modify(grid, i, j))
				{
					++result;
				}
			}
		}
		for (int i = 0; i < cols; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				grid[i][j] = (grid[i][j] == '0') ? '0' : '1';
			}
		}
		return result;
	}
};

/*
idea: depth first search
complexity: Time O(N)
*/

int main(void)
{
	vector<vector<char> > grid(2, vector<char>(2, '1'));
	Solution engine;
	cout << engine.numIslands(grid) << '\n';
	return 0;
}
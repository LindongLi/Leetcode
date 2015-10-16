#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/set-matrix-zeroes/

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution
{
public:
	void setZeroes(vector<vector<int> >& matrix)
	{
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		if (n == 0) return;
		// project 0 to first row & column serving as marks
		// attention (0, 0) has two project directions, and two boolean will distinguish them
		bool zerofirstrow = false;
		bool zerofirstcol = false;
		for (int row = 0; row < m; ++row)	// horizontal
		{
			for (int col = 0; col < n; ++col)	// vertical
			{
				if (matrix[row][col] != 0) continue;
				// project to first col, controls row zero
				if (row != 0)
				{
					matrix[row][0] = 0;
				}
				else zerofirstrow = true;
				// project to first row, controls col zero
				if (col != 0)
				{
					matrix[0][col] = 0;
				}
				else zerofirstcol = true;
			}
		}
		// read first col zeros and expand to corresponding row
		for (int row = 1; row < m; ++row)
		{
			if (matrix[row][0] != 0) continue;
			for (int col = 1; col < n; ++col)
			{
				matrix[row][col] = 0;
			}
		}
		// read first row zeros and expand to corresponding col
		for (int col = 1; col < n; ++col)
		{
			if (matrix[0][col] != 0) continue;
			for (int row = 1; row < m; ++row)
			{
				matrix[row][col] = 0;
			}
		}
		// processing boolean
		if (zerofirstrow)
		{
			for (int col = 0; col < n; ++col)
			{
				matrix[0][col] = 0;
			}
		}
		if (zerofirstcol)
		{
			for (int row = 0; row < m; ++row)
			{
				matrix[row][0] = 0;
			}
		}
	}
};

/*
idea: using first row & column as zero masks
complexity: Time O(N^2)
*/

int main(void)
{
	vector<vector<int> > matrix;
	vector<int> nums(3);
	nums[0] = 1;
	nums[1] = 0;
	nums[2] = 0;
	matrix.push_back(nums);
	Solution engine;
	engine.setZeroes(matrix);
	return 0;
}
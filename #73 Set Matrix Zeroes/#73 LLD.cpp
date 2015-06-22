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
		int n = matrix.size();
		if (n == 0) return;
		int m = matrix[0].size();
		// project 0 to first row & column serving as marks
		// attention (0, 0) has two project directions, and two boolean will distinguish them
		bool zerofirstcol = false;
		bool zerofirstrow = false;
		for (int r = 0; r < n; r++)	// horizontal
		{
			for (int c = 0; c < m; c++)	// vertical
			{
				if (matrix[r][c] == 0)
				{
					// project to first row, controls col zero
					if (c != 0)
					{
						matrix[0][c] = 0;
					}
					else zerofirstcol = true;
					// project to first col, controls row zero
					if (r != 0)
					{
						matrix[r][0] = 0;
					}
					else zerofirstrow = true;
				}
			}
		}
		// read first row zeros and expand to corresponding col
		for (int c = 1; c < m; c++)
		{
			if (matrix[0][c] == 0)
			{
				for (int r = 1; r < n; r++)
				{
					matrix[r][c] = 0;
				}
			}
		}
		// read first col zeros and expand to corresponding row
		for (int r = 1; r < n; r++)
		{
			if (matrix[r][0] == 0)
			{
				for (int c = 1; c < m; c++)
				{
					matrix[r][c] = 0;
				}
			}
		}
		// processing boolean
		if (zerofirstcol)
		{
			for (int r = 0; r < n; r++)
			{
				matrix[r][0] = 0;
			}
		}
		if (zerofirstrow)
		{
			for (int c = 0; c < m; c++)
			{
				matrix[0][c] = 0;
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
	vector<int> nums;
	nums.resize(3);
	nums[0] = 1;
	nums[1] = 0;
	nums[2] = 0;
	matrix.push_back(nums);
	Solution engine;
	engine.setZeroes(matrix);
	return 0;
}
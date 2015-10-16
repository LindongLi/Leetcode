#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution
{
public:
	void rotate(vector<vector<int> >& matrix)
	{
		int n = matrix.size() - 1;
		for (int row = 0; row < ((n + 1) >> 1); ++row)
		{
			for (int col = 0; col <= (n >> 1); ++col)	// different criteria
			{
				int cache = matrix[row][col];
				matrix[row][col] = matrix[n - col][row];
				matrix[n - col][row] = matrix[n - row][n - col];
				matrix[n - row][n - col] = matrix[col][n - row];
				matrix[col][n - row] = cache;
			}
		}
	}
};

/*
idea: divide into four sub-squares, attention rows & cols have different boundary
complexity: Time O(logN)
*/

int main(void)
{
	vector<vector<int> > matrix;
	vector<int> nums(2);
	nums[0] = 1;
	nums[1] = 2;
	matrix.push_back(nums);
	nums[0] = 3;
	nums[1] = 4;
	matrix.push_back(nums);
	Solution engine;
	engine.rotate(matrix);
	return 0;
}
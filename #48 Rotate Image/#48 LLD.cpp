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
		for (int y = 0; y < ((n + 1) >> 1); y++)
		{
			for (int x = 0; x <= (n >> 1); x++)	// different criteria
			{
				int cache = matrix[y][x];
				matrix[y][x] = matrix[n - x][y];
				matrix[n - x][y] = matrix[n - y][n - x];
				matrix[n - y][n - x] = matrix[x][n - y];
				matrix[x][n - y] = cache;
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
	vector<int> nums;
	nums.resize(2);
	nums[0] = 1;
	nums[1] = 2;
	matrix.push_back(nums);
	nums[0] = 3;
	nums[1] = 4;
	matrix.push_back(nums);
	Solution engine;
	engine.rotate(matrix);
	cout << matrix[0][0] << '\n';
	return 0;
}
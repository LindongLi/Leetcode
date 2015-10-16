#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution
{
private:
	vector<int>::iterator data;
	bool search(int min, int max, int target)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (data[mid] > target)
			{
				max = mid;
			}
			else
			{
				min = mid;
			}
		}
		return (data[min] == target) || (data[max] == target);
	}
public:
	bool searchMatrix(vector<vector<int> >& matrix, int target)
	{
		vector<vector<int> >::iterator col = matrix.begin();
		for (; (col != matrix.end()) && (col[0][0] <= target); ++col)
		{
			data = col[0].begin();
			if (search(0, col[0].size() - 1, target))
			{
				return true;
			}
		}
		return false;
	}
};

/*
idea: loop and binary search each column
complexity: Time O(NlogN)
*/

int main(void)
{
	vector<vector<int> > matrix;
	vector<int> nums(5);
	nums[0] = 1;
	nums[1] = 4;
	nums[2] = 7;
	nums[3] = 11;
	nums[3] = 15;
	matrix.push_back(nums);
	Solution engine;
	cout << engine.searchMatrix(matrix, 5) << '\n';
	return 0;
}
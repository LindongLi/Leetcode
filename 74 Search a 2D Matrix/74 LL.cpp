#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution
{
private:
	vector<int>::iterator data;
	bool binarysearch(int target, int min, int max)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (target <= data[mid])
			{
				max = mid;
			}
			else
			{
				min = mid + 1;
			}
		}
		if (target == data[min]) return true;
		if (target == data[max]) return true;
		return false;
	}
public:
	bool searchMatrix(vector<vector<int> >& matrix, int target)
	{
		vector<vector<int> >::iterator col = matrix.begin();
		for (; (col != matrix.end()) && (col[0][0] <= target); ++col)
		{
			data = col[0].begin();
			if (binarysearch(target, 0, col[0].size() - 1))
			{
				return true;
			}
		}
		return false;
	}
};

/*
idea: column for loop, row binary search
complexity: Time O(NlogN)
*/

int main(void)
{
	vector<vector<int> > matrix;
	vector<int> nums(4);
	nums[0] = 1;
	nums[1] = 3;
	nums[2] = 5;
	nums[3] = 7;
	matrix.push_back(nums);
	Solution engine;
	cout << engine.searchMatrix(matrix, 3) << '\n';
	return 0;
}
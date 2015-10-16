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
	bool search(int min, int max, int target)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (data[mid] > target)
			{
				max = mid - 1;
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
		int min = 0, max = matrix.size() - 1;
		vector<vector<int> >::iterator col = matrix.begin();
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (col[mid][0] > target)
			{
				max = mid - 1;
			}
			else
			{
				min = mid;
			}
		}
		int select = (col[max][0] > target) ? min : max;
		data = col[select].begin();
		return search(0, col[select].size() - 1, target);
	}
};

/*
idea: column binary search, then row binary search
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
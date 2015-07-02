#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/triangle/

Given a triangle, find the minimum path sum from top to bottom.
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.
*/

class Solution
{
public:
	int minimumTotal(vector<vector<int> > &triangle)
	{
		if (triangle.size() == 0) return 0;
		vector<vector<int> >::iterator row = triangle.end() - 1;
		vector<int> space(row[0]);	// copy last row
		for (; row != triangle.begin(); --row)
		{
			vector<int>::iterator data = row[-1].begin();
			vector<int>::iterator source = space.begin();
			for (; data != row[-1].end(); ++data, ++source)
			{
				// left source represent upper row
				source[0] = data[0] + min(source[0], source[1]);
			}
		}
		return space[0];
	}
};

/*
idea: choose branch & summary bottom up
complexity: Time O(N^2)
*/

int main(void)
{
	vector<vector<int> > triangle;
	vector<int> nums(1);
	nums[0] = 2;
	triangle.push_back(nums);
	nums.resize(2);
	nums[0] = 3;
	nums[1] = 4;
	triangle.push_back(nums);
	nums.resize(3);
	nums[0] = 6;
	nums[1] = 5;
	nums[2] = 7;
	triangle.push_back(nums);
	nums.resize(4);
	nums[0] = 4;
	nums[1] = 1;
	nums[2] = 8;
	nums[3] = 3;
	triangle.push_back(nums);
	Solution engine;
	cout << engine.minimumTotal(triangle) << '\n';
	return 0;
}
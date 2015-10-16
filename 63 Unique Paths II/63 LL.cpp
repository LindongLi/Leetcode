#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/unique-paths-ii/

Follow up for "Unique Paths (#62)":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
	{
		vector<vector<int> >::iterator row = obstacleGrid.begin();
		vector<int>::iterator last;	// remember last row
		if (row == obstacleGrid.end()) return 0;
		else	// initialize first row
		{
			vector<int>::iterator data = row[0].begin();
			int lastdata = 1;
			for (; data != row[0].end(); ++data)
			{
				if (data[0] == 1) data[0] = 0;
				else
				{
					data[0] = lastdata;
				}
				lastdata = data[0];
			}
			last = row[0].begin();
			++row;
		}
		for (; row != obstacleGrid.end(); ++row)
		{
			vector<int>::iterator data = row[0].begin();
			int lastdata = 0;
			for (; data != row[0].end(); ++data, ++last)
			{
				if (data[0] == 1) data[0] = 0;
				else
				{
					data[0] = lastdata + last[0];
				}
				lastdata = data[0];
			}
			last = row[0].begin();
		}
		return obstacleGrid.back().back();
	}
};

/*
idea: dynamic programing
complexity: Time O(N)
*/

int main(void)
{
	vector<vector<int> > obstacleGrid;
	vector<int> nums(3);
	obstacleGrid.push_back(nums);
	nums[1] = 1;
	obstacleGrid.push_back(nums);
	nums[1] = 0;
	obstacleGrid.push_back(nums);
	Solution engine;
	cout << engine.uniquePathsWithObstacles(obstacleGrid) << '\n';
	return 0;
}
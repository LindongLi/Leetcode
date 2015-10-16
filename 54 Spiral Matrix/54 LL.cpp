#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example, Given the following matrix:
[
	[ 1, 2, 3 ],
	[ 4, 5, 6 ],
	[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution
{
private:
	vector<int> route;
	void calculate(int m, int n)
	{
		// starting (0, -1) tracing direction steps
		route.clear();
		while (1)
		{
			route.push_back(n);	// right
			if (--m == 0) break;
			route.push_back(m);	// down
			if (--n == 0) break;
			route.push_back(n);	// left
			if (--m == 0) break;
			route.push_back(m);	// up
			if (--n == 0) break;
		}
	}
public:
	vector<int> spiralOrder(vector<vector<int> >& matrix)
	{
		vector<int> result;
		int m = matrix.size();	// rows
		if (m == 0) return result;
		int n = matrix[0].size();	// columns
		if (n == 0) return result;
		calculate(m, n);
		int posm = 0, posn = -1;
		const int dm[4] = {0, 1, 0, -1};
		const int dn[4] = {1, 0, -1, 0};
		for (int i = 0; i < route.size(); ++i)
		{
			for (int go = 0; go < route[i]; ++go)
			{
				posm += dm[i & 0x3];
				posn += dn[i & 0x3];
				result.push_back(matrix[posm][posn]);
			}
		}
		return result;
	}
};

/*
idea: route calculating
complexity: Time O(N^2)
*/

int main(void)
{
	vector<vector<int> > matrix;
	vector<int> nums(3);
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	matrix.push_back(nums);
	nums[0] = 4;
	nums[1] = 5;
	nums[2] = 6;
	matrix.push_back(nums);
	nums[0] = 7;
	nums[1] = 8;
	nums[2] = 9;
	matrix.push_back(nums);
	Solution engine;
	cout << engine.spiralOrder(matrix).size() << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/pascals-triangle/

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution
{
public:
	vector<vector<int> > generate(int numRows)
	{
		vector<vector<int> > result(numRows);
		for (int i = 0; i < numRows; ++i)
		{
			result[i].resize(i + 1);
			result[i][0] = 1;
			result[i][i] = 1;
			for (int j = 1; j < i; ++j)
			{
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}
		return result;
	}
};

/*
idea: build new line using previous line
complexity: O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.generate(3).size() << '\n';
	return 0;
}
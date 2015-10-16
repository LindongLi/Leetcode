#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/pascals-triangle-ii/

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> result;
		result.resize(rowIndex + 1);
		long long int cache = 1;
		for (int i = 0, ri = rowIndex; i <= ri; ++i, --ri)
		{
			result[i] = result[ri] = (int)cache;
			cache = cache * (rowIndex - i) / (i + 1);
		}
		return result;
	}
};

/*
idea: math calculation using combination
complexity: O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.getRow(6).size() << '\n';
	return 0;
}
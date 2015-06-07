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
		result[0] = 1;
		result[rowIndex] = 1;
		for(int i = 1, ri = rowIndex - 1; i <= ri; i++, ri--)
		{
			long long unsigned int cache = result[i - 1];
			cache = cache * (rowIndex + 1 - i) / i;
			result[i] = (int)cache;
			result[ri] = (int)cache;
		}
		return result;
	}
};

/*
idea: math calculation using combine
complexity: O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.getRow(6).size() << '\n';
	return 0;
}
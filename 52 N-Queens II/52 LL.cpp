#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/n-queens-ii/

Follow up for N-Queens problem (#51).

Now, instead outputting board configurations,
return the total number of distinct solutions.
*/

class Solution
{
private:
	vector<int> trace;
public:
	int totalNQueens(int n)
	{
		int totalrow = trace.size();
		if (totalrow == n) return 1;
		int result = 0;
		for (int x = 0; x < n; ++x)
		{
			int y = 0;	// rows index
			for (; y < totalrow; ++y)
			{
				if (x == trace[y]) break;
				if (abs(x - trace[y]) == abs(totalrow - y))
				{
					break;
				}
			}
			if (y == totalrow)
			{
				trace.push_back(x);
				result += totalNQueens(n);
				trace.pop_back();
			}
		}
		return result;
	}
};

/*
idea: depth first search
complexity: Time O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.totalNQueens(7) << '\n';
	return 0;
}
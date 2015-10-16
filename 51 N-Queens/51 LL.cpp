#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution
{
private:
	vector<int> trace;
	vector<vector<string> > result;
	void oneanswer(int n)
	{
		string row(n, '.');
		vector<string> answer;
		for (int i = 0; i < n; ++i)
		{
			row[trace[i]] = 'Q';
			answer.push_back(row);
			row[trace[i]] = '.';
		}
		result.push_back(answer);
	}
	void search(int n)
	{
		int totalrow = trace.size();
		if (totalrow == n)
		{
			oneanswer(n);
			return;
		}
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
				search(n);
				trace.pop_back();
			}
		}
	}
public:
	vector<vector<string> > solveNQueens(int n)
	{
		search(n);
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
	cout << engine.solveNQueens(4).size() << '\n';
	return 0;
}
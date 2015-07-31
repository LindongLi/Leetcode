#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/sudoku-solver/

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

class Solution
{
private:
	vector<vector<char> >::iterator data;
	bool isvalid(int m, int n, char &cnext)
	{
		vector<bool> map(9, false);
		for (int i = 0; i < 9; ++i)
		{
			if (data[m][i] != '.')
			{
				map[size_t(data[m][i] - '1')] = true;
			}
			if (data[i][n] != '.')
			{
				map[size_t(data[i][n] - '1')] = true;
			}
		}
		int mbase = m - m % 3;
		int nbase = n - n % 3;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (data[mbase + i][nbase + j] == '.') continue;
				map[size_t(data[mbase + i][nbase + j] - '1')] = true;
			}
		}
		for (int i = 0; i < 9; ++i)
		{
			if (map[i] == true) continue;
			if (cnext < char('1' + i))
			{
				cnext = char('1' + i);
				return true;
			}
		}
		return false;
	}
	bool search(int m, int n = 0)
	{
		for (; m < 9; ++m)
		{
			for (; n < 9; ++n)
			{
				if (data[m][n] != '.') continue;
				char c = '\0';
				while (isvalid(m, n, c))
				{
					data[m][n] = c;
					if (search(m, n + 1)) return true;
				}
				data[m][n] = '.';
				return false;
			}
			n = 0;	// next row
		}
		return true;
	}
public:
	void solveSudoku(vector<vector<char> >& board)
	{
		if (board.size() != 9) return;
		data = board.begin();
		search(0);
	}
};

/*
idea: depth first search
complexity: Time O(N^2)
*/

int main(void)
{
	vector<vector<char> > board(9, vector<char>(9, '.'));
	Solution engine;
	engine.solveSudoku(board);
	return 0;
}
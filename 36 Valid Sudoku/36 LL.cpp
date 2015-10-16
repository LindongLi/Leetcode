#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/valid-sudoku/

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution
{
public:
	bool isValidSudoku(vector<vector<char> >& board)
	{
		if (board.size() != 9) return false;
		for (int m = 0; m < 9; ++m)
		{
			vector<bool> dmap(9, false);
			vector<bool> vmap(9, false);
			for (int n = 0; n < 9; ++n)
			{
				if (board[m][n] != '.')
				{
					if (dmap[size_t(board[m][n] - '1')])
					{
						return false;
					}
					dmap[size_t(board[m][n] - '1')] = true;
				}
				if (board[n][m] != '.')
				{
					if (vmap[size_t(board[n][m] - '1')])
					{
						return false;
					}
					vmap[size_t(board[n][m] - '1')] = true;
				}
			}
		}
		for (int m = 0; m < 9; m += 3)
		{
			for (int n = 0; n < 9; n += 3)
			{
				vector<bool> map(9, false);
				for (int i = 0; i < 3; ++i)
				{
					for (int j = 0; j < 3; ++j)
					{
						if (board[m + i][n + j] != '.')
						{
							if (map[size_t(board[m + i][n + j] - '1')])
							{
								return false;
							}
							map[size_t(board[m + i][n + j] - '1')] = true;
						}
					}
				}
			}
		}
		return true;
	}
};

/*
idea: familiar with Sudoku rules
complexity: Time O(N^2)
*/

int main(void)
{
	vector<vector<char> > board;
	Solution engine;
	cout << engine.isValidSudoku(board) << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/surrounded-regions/

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution
{
private:
	vector<int> rtrace;
	vector<int> ctrace;
public:
	void solve(vector<vector<char> >& board)
	{
		int row = board.size();
		if (row == 0) return;
		int col = board[0].size();
		if (col == 0) return;
		for (int i = 0; i < col; ++i)
		{
			if (board[0][i] == 'O')
			{
				rtrace.push_back(0);
				ctrace.push_back(i);
			}
			if ((row > 1) && (board[row - 1][i] == 'O'))
			{
				rtrace.push_back(row - 1);
				ctrace.push_back(i);
			}
		}
		for (int i = 1; i < (row - 1); ++i)
		{
			if (board[i][0] == 'O')
			{
				rtrace.push_back(i);
				ctrace.push_back(0);
			}
			if ((col > 1) && (board[i][col - 1] == 'O'))
			{
				rtrace.push_back(i);
				ctrace.push_back(col - 1);
			}
		}
		while (!rtrace.empty())
		{
			int r = rtrace.back();
			int c = ctrace.back();
			rtrace.pop_back();
			ctrace.pop_back();
			board[r][c] = 'S';
			if ((r > 1) && (board[r - 1][c] == 'O'))
			{
				rtrace.push_back(r - 1);
				ctrace.push_back(c);
			}
			if ((r < (row - 2)) && (board[r + 1][c] == 'O'))
			{
				rtrace.push_back(r + 1);
				ctrace.push_back(c);
			}
			if ((c > 1) && (board[r][c - 1] == 'O'))
			{
				rtrace.push_back(r);
				ctrace.push_back(c - 1);
			}
			if ((c < (col - 2)) && (board[r][c + 1] == 'O'))
			{
				rtrace.push_back(r);
				ctrace.push_back(c + 1);
			}
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				board[i][j] = (board[i][j] == 'S') ? 'O' : 'X';
			}
		}
	}
};

/*
idea: width first search
complexity: Time O(N^2)
*/

int main(void)
{
	vector<vector<char> > board;
	Solution engine;
	engine.solve(board);
	return 0;
}
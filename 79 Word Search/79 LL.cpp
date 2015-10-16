#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution
{
private:
	int m, n;
	vector<vector<char> >::iterator data;
	bool step(int posm, int posn, const char *c)
	{
		if (c[0] == '\0') return true;
		if (c[0] == data[posm][posn])
		{
			data[posm][posn] = '\0';	// mark used
			bool checked = true;
			do
			{
				if ((posm > 0) && step(posm - 1, posn, c + 1)) break;
				if ((posn > 0) && step(posm, posn - 1, c + 1)) break;
				if ((posm < (m - 1)) && step(posm + 1, posn, c + 1)) break;
				if ((posn < (n - 1)) && step(posm, posn + 1, c + 1)) break;
				checked = (c[1] == '\0');
			}
			while (false);
			data[posm][posn] = c[0];
			return checked;
		}
		return false;
	}
public:
	bool exist(vector<vector<char> >& board, string word)
	{
		Solution::m = board.size();
		if (m == 0) return false;
		Solution::n = board[0].size();
		if (n == 0) return false;
		data = board.begin();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (step(i, j, word.data())) return true;
			}
		}
		return false;
	}
};

/*
idea: mimic checking step
complexity: Time O(N^3)
*/

int main(void)
{
	vector<vector<char> > board;
	vector<char> chars(2);
	chars[0] = 'A';
	chars[1] = 'B';
	board.push_back(chars);
	chars[0] = 'C';
	chars[1] = 'D';
	board.push_back(chars);
	Solution engine;
	cout << engine.exist(board, "ABDC") << '\n';
	return 0;
}
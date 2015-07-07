#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Zigzag pattern demo:
13		1 5		1  7
24		246		2 68
		3 7		35 9
				4  A
Every zigzag has 2 * nRows - 2
*/

class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (numRows <= 1) return s;
		string result;
		const int maxlen = s.length();
		const int groupnum = numRows + numRows - 2;

		//processing header
		int pos = 0;
		while (pos < maxlen)
		{
			result += s[pos];
			pos += groupnum;
		}
		//processing middle
		for (int i = 1; i < (numRows - 1); ++i)
		{
			int posa = i, posb = groupnum - i;
			while (1)
			{
				if (posa >= maxlen) break;
				result += s[posa];
				posa += groupnum;
				if (posb >= maxlen) break;
				result += s[posb];
				posb += groupnum;
			}
		}
		//processing tail
		pos = numRows - 1;
		while (pos < maxlen)
		{
			result += s[pos];
			pos += groupnum;
		}
		return result;
	}
};

/*
idea: 2-dimensional position mapping
complexity: O(N)
*/

int main(void)
{
	string s("PAYPALISHIRING");
	Solution engine;
	cout << engine.convert(s, 3) << '\n';
	return 0;
}
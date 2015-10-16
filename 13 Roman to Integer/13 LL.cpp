#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/roman-to-integer/

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution
{
private:
	static int getvalue(char c)
	{
		switch (c)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}
public:
	int romanToInt(string s)
	{
		int result = 0;
		int curval = 0;
		string::iterator data = s.begin();
		for (; data != s.end(); ++data)
		{
			int nextval = getvalue(data[0]);
			result += (curval < nextval) ? -curval : curval;
			curval = nextval;
		}
		result += curval;
		return result;
	}
};

/*
idea: https://en.wikipedia.org/wiki/Roman_numerals
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.romanToInt("MCMLIV") << '\n';
	return 0;
}
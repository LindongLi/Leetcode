#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/excel-sheet-column-number/

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/

class Solution
{
public:
	int titleToNumber(string s)
	{
		int result = 0;
		string::iterator data = s.begin();
		for (; data != s.end(); ++data)
		{
			result *= 26;
			result += int(data[0] - 'A' + 1);
		}
		return result;
	}
};

/*
idea: similar to string to integer
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.titleToNumber("AA") << '\n';
	return 0;
}
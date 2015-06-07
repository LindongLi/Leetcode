#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/string-to-integer-atoi/

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases.
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.
*/

class Solution
{
public:
	int myAtoi(string str)
	{
		int pos = 0;
		int result = 0;
		bool neg = false;
		while(str[pos] == ' ') pos++;
		if(str[pos] == '+')
		{
			pos++;
		}
		else if(str[pos] == '-')
		{
			pos++;
			neg = true;
		}
		while((str[pos] >= '0') && (str[pos] <= '9'))
		{
			int digit = str[pos++] - '0';
			if((result > 214748364) || ((result == 214748364) && (digit > 7)))
			{
				return neg ? -2147483648 : 2147483647;	// handle overflow
			}
			result *= 10;
			result += digit;
		}
		return neg ? (-result) : result;
	}
};

/*
idea: simple :)
complexity: O(1)
*/

int main(void)
{
	Solution engine;
	cout << engine.myAtoi("  -+1...") << '\n';
	return 0;
}
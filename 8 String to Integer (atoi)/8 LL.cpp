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
		string::iterator data = str.begin();
		while ((data != str.end()) && (data[0] == ' '))
		{
			++data;
		}
		bool neg;
		if ((data != str.end()) && ((data[0] == '+') || (data[0] == '-')))
		{
			neg = (data[0] == '-');
			++data;
		}
		long long int result = 0;
		while (data != str.end())
		{
			if ((data[0] < '0') || (data[0] > '9')) break;
			result = result * 10 + int(data[0] - '0');
			if (result > 0x7FFFFFFF)
			{
				return neg ? ~0x7FFFFFFF : 0x7FFFFFFF;
			}
			++data;
		}
		return neg ? -int(result) : int(result);
	}
};

/*
idea: careful handle overflow
complexity: O(1)
*/

int main(void)
{
	Solution engine;
	cout << engine.myAtoi("-12345678901") << '\n';
	return 0;
}
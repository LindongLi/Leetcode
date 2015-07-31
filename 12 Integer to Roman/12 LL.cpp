#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/integer-to-roman/

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution
{
private:
	string result;
	void fill(int &num, int mask, string s)
	{
		if (num >= (mask * 9))
		{
			num -= mask * 9;
			result += s[2];
			result += s[0];
			return;
		}
		if (num >= (mask * 5))
		{
			num -= mask * 5;
			result += s[1];
		}
		if (num >= (mask * 4))
		{
			num -= mask	* 4;
			result += s[2];
			result += s[1];
			return;
		}
		while (num >= mask)
		{
			num -= mask;
			result += s[2];
		}
	}
public:
	string intToRoman(int num)
	{
		fill(num, 1000, "**M");
		fill(num, 100, "MDC");
		fill(num, 10, "CLX");
		fill(num, 1, "XVI");
		return result;
	}
};

/*
idea: 4 and 9 special cases
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.intToRoman(1) << '\n';
	return 0;
}
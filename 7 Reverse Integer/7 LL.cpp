#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution
{
public:
	int reverse(int x)
	{
		if (x == 0x80000000) return 0;	// handle MIN_INT
		bool neg = (x < 0);
		x = neg ? -x : x;
		int digits[12];
		int pos = 0;
		do
		{
			digits[pos++] = x % 10;
			x /= 10;
		}
		while (x != 0);
		long long int result = 0;
		for (int i = 0; i < pos; ++i)
		{
			result = result * 10 + digits[i];
		}
		result = (result > 0x7FFFFFFF) ? 0 : result;
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
	cout << engine.reverse(-123) << '\n';
	return 0;
}
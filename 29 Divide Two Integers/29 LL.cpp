#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/divide-two-integers/

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0) return 0x7FFFFFFF;
		bool neg = (dividend < 0) ^ (divisor < 0);
		unsigned int a = (dividend < 0) ? -dividend : dividend;
		unsigned int b = (divisor < 0) ? -divisor : divisor;
		unsigned int result = 0, mask = 1;
		while ((a >> 1) >= b)
		{
			b <<= 1;
			mask <<= 1;
		}
		while (mask != 0)
		{
			if (a >= b)
			{
				a -= b;
				result |= mask;
			}
			b >>= 1;
			mask >>= 1;
		}
		// attention unsigned to signed MIN_INT overflow
		return neg ? -int(result) : int((result > 0x7FFFFFFF) ? 0x7FFFFFFF : result);
	}
};

/*
idea: bit subtraction and shift
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.divide(0x80000001, 1) << '\n';
	return 0;
}
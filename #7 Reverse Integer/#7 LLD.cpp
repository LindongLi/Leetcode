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
		if(x == -x) return 0;	// handle "-2147483648", weird input
		int digits[12];
		bool neg = false;
		int stack_pos = 0;
		if(x < 0)
		{
			x = -x;
			neg = true;
		}
		do
		{
			digits[stack_pos++] = x % 10;
			x /= 10;
		}
		while(x != 0);
		int result = 0;
		for(int i = 0; i < stack_pos; i++)
		{
			if((result > 214748364) || ((result == 214748364) && (digits[i] > 7)))
			{
				return 0;	// handle overflow
			}
			result *= 10;
			result += digits[i];
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
	cout << engine.reverse(-2147483648) << '\n';
	return 0;
}
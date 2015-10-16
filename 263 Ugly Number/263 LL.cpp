#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/ugly-number/

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

class Solution
{
public:
	bool isUgly(int num)
	{
		if (num <= 0) return false;
		while ((num & 0x1) == 0)
		{
			num >>= 1;
		}
		while ((num % 3) == 0)
		{
			num /= 3;
		}
		while ((num % 5) == 0)
		{
			num /= 5;
		}
		return (num == 1);
	}
};

/*
idea: eliminate all prime factors
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isUgly(14) << '\n';
	return 0;
}
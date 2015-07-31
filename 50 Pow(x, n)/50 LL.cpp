#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/powx-n/

Implement pow(x, n).
*/

class Solution
{
public:
	double myPow(double x, int n)
	{
		bool reverse = (n < 0);
		if (n < 0) n = -n;
		double result = 1;
		while (n > 0)
		{
			if (n & 0x1)
			{
				result *= x;
			}
			x = x * x;
			n >>= 1;
		}
		return reverse ? (1 / result) : result;
	}
};

/*
idea: power mask multiply
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.myPow(1.1, 2) << '\n';
	return 0;
}
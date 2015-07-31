#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/sqrtx/

Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution
{
public:
	int mySqrt(int x)
	{
		if (x <= 0) return 0;
		long long int s = x, n = 1;
		while ((n * n > x) || (n * n <= (x - n - n - 1)))
		{
			n = (n + x / n) >> 1;
		}
		return int(n);
	}
};

/*
idea: newton's method, attention int overflow
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.mySqrt(0) << '\n';
	return 0;
}
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/

Given a range [m, n] where 0 <= m <= n <= 2147483647,
return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

class Solution
{
private:
	static int highestbit(int x)
	{
		x |= (x >> 1);
		x |= (x >> 2);
		x |= (x >> 4);
		x |= (x >> 8);
		x |= (x >> 16);
		return x ^ (x >> 1);
	}
public:
	int rangeBitwiseAnd(int m, int n)
	{
		int mstt = highestbit(m);
		int nstt = highestbit(n);
		if ((mstt ==  nstt) && (mstt != 0))
		{
			m ^= mstt;
			n ^= mstt;
			return (rangeBitwiseAnd(m, n) | mstt);
		}
		return 0;
	}
};

/*
idea: find highest bit
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.rangeBitwiseAnd(5, 7) << '\n';
	return 0;
}
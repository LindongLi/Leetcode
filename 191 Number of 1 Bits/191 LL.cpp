#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/number-of-1-bits/

Write a function that takes an unsigned integer and returns the number of ’1' bits it has
(also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
so the function should return 3.
*/

class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int result = 0;
		while (n != 0)
		{
			++result;
			n = n & (n - 1);
		}
		return result;
	}
};

/*
idea: bit manipulate
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.hammingWeight(11) << '\n';
	return 0;
}
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution
{
public:
	int trailingZeroes(int n)
	{
		int result = 0;
		for (int f = 5; ; f *= 5)
		{
			int count = n / f;
			result += count;
			if (count < 5) break;
		}
		return result;
	}
};

/*
idea: count 5 and 25 and 125 and all 5 factors
complexity: Time O(logN)
*/

int main(void)
{
	Solution engine;
	cout << engine.trailingZeroes(30) << '\n';
	return 0;
}
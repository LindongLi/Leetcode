#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/power-of-two/

Given an integer, write a function to determine if it is a power of two.
*/

class Solution
{
public:
	bool isPowerOfTwo(int n)
	{
		if (n <= 0) return false;
		return (n & (n - 1)) == 0;
	}
};

/*
idea: bit manipulate
complexity: Time O(1)
*/

int main(void)
{
	Solution engine;
	cout << engine.isPowerOfTwo(8) << '\n';
	return 0;
}
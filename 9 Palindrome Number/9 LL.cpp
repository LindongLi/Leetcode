#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
		{
			return false;
		}
		int mask = 1;
		while ((x / 10) >= mask)
		{
			mask *= 10;
		}
		while (mask > 1)
		{
			if (((x - x / mask) % 10) != 0)
			{
				return false;
			}
			x /= 10;
			mask /= 100;
		}
		return true;
	}
};

/*
idea: compare head and tail
complexity: O(1)
*/

int main(void)
{
	Solution engine;
	cout << engine.isPalindrome(221) << '\n';
	return 0;
}
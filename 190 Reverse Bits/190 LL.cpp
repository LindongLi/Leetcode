#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/reverse-bits/

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
return 964176192 (represented in binary as 00111001011110000010100101000000).
*/

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		static const uint32_t map[8] = {0, 2, 1, 3};
		uint32_t output = 0;
		int counter = 16;
		while (1)
		{
			output += map[n & 0x3];
			if (--counter == 0) break;
			output <<= 2;
			n >>= 2;
		}
		return output;
	}
};

/*
idea: bit manipulate
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.reverse(1) << '\n';
	return 0;
}
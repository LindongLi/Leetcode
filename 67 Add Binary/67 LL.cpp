#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/add-binary/

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string result;
		string::reverse_iterator va = a.rbegin();
		string::reverse_iterator vb = b.rbegin();
		int carry = 0;
		while (true)
		{
			bool looping = (carry != 0);
			if (va != a.rend())
			{
				looping = true;
				carry += (va[0] == '1') ? 1 : 0;
				++va;
			}
			if (vb != b.rend())
			{
				looping = true;
				carry += (vb[0] == '1') ? 1 : 0;
				++vb;
			}
			if (!looping) break;
			result += '0' + (carry & 0x1);
			carry >>= 1;
		}
		if (result.length() != 0)
		{
			reverse(result.begin(), result.end());
		}
		else result += '0';	// handle empty input
		return result;
	}
};

/*
idea: simulate bit-based adding
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.addBinary("11", "1") << '\n';
	return 0;
}
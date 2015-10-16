#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/decode-ways/

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution
{
public:
	int numDecodings(string s)
	{
		if ((s.size() == 0) || (s[0] == '0')) return 0;
		vector<int> map(s.length() + 1);
		string::iterator data = s.begin() + 1;
		vector<int>::iterator it = map.begin() + 2;
		for (it[-2] = it[-1] = 1; data != s.end(); ++data, ++it)
		{
			if (data[0] == '0')
			{
				if ((data[-1] < '1') || (data[-1] > '2')) return 0;
			}
			else it[0] = it[-1];
			if ((data[-1] == '1') || ((data[-1] == '2') && ('0' <= data[0]) && (data[0] <= '6')))
			{
				it[0] += it[-2];
			}
		}
		return map.back();
	}
};

/*
idea: dynamic programing
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.numDecodings("2100") << '\n';
	return 0;
}
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/implement-strstr/

Implement strStr().
Returns the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*/

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		for (int i = 0; ; ++i)
		{
			for (int j = 0; ; ++j)
			{
				if (j >= needle.size())
				{
					return i;
				}
				if ((i + j) >= haystack.size())
				{
					return -1;
				}
				if (haystack[i + j] != needle[j]) break;
			}
		}
		return -1;
	}
};

/*
idea: unordered_map uses hash, constant time search
complexity: Time O(N) Space O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.strStr("abcdd", "dd") << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/regular-expression-matching/

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution
{
private:
	string::iterator sdata;
	string::iterator pdata;
	static bool match(char s, char p)
	{
		return (p == '.') || (s == p);
	}
	bool search(int slen, int plen)
	{
		if (slen == 0)
		{
			if (plen == 0) return true;
			if ('*' == pdata[plen - 1])
			{
				return search(slen, plen - 2);
			}
			return false;
		}
		if (plen == 0) return false;
		if ('*' == pdata[plen - 1])
		{
			if (search(slen, plen - 2))
			{
				return true;
			}
			while ((slen > 0) && match(sdata[slen - 1], pdata[plen - 2]))
			{
				--slen;
				if (search(slen, plen - 2))
				{
					return true;
				}
			}
			return false;
		}
		if (!match(sdata[slen - 1], pdata[plen - 1]))
		{
			return false;
		}
		return search(slen - 1, plen - 1);
	}
public:
	bool isMatch(string s, string p)
	{
		sdata = s.begin();
		pdata = p.begin();
		return search(s.size(), p.size());
	}
};

/*
idea: recursive
complexity: Time very ugly
*/

int main(void)
{
	Solution engine;
	cout << engine.isMatch("caaaaaaaaaaaaaaaaaaaaa", "a*a*a*a*a*a*a*a*") << '\n';
	return 0;
}
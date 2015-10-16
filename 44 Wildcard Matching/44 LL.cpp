#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/wildcard-matching/

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int plen = p.size();
		vector<bool> pre(plen + 1);
		vector<bool> map(plen + 1);
		map[0] = true;
		for (int i = 1; i <= plen; ++i)
		{
			map[i] = map[i - 1] && (p[i - 1] == '*');
		}
		for (int i = 0; i < s.size(); ++i)
		{
			pre.swap(map);
			map[0] = false;
			for (int j = 1; j <= plen; ++j)
			{
				if (p[j - 1] == '*')
				{
					map[j] = map[j - 1] || pre[j];
				}
				else
				{
					map[j] = pre[j - 1] && ((s[i] == p[j - 1]) || (p[j - 1] == '?'));
				}
			}
		}
		return map.back();
	}
};

/*
idea: dynamic programming, caution zero case
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isMatch("bbbaab", "a**?***") << '\n';
	return 0;
}
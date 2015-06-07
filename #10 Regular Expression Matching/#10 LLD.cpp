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
public:
	bool isMatch(string s, string p)
	{
		int ns = 0, es = s.length() - 1;
		int np = 0, ep = p.length() - 1;
		
	}
};
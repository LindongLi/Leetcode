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
private:
	string::iterator sEnd;
	string::iterator pEnd;
	bool match(string::iterator sStt, string::iterator pStt)
	{
		if ((sStt == sEnd) && (pStt == pEnd)) return true;
		if (sStt != sEnd)
		{

		}
	}
public:
	bool isMatch(string s, string p)
	{
		string::iterator data = s.begin();
		for (; data != s.end(); ++data)
		{
			switch
		}
}
};
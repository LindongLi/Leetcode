#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/longest-palindromic-substring/

Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.

Attention! SubString and SubSequences ARE DIFFERENT!
http://en.wikipedia.org/wiki/Substring
http://en.wikipedia.org/wiki/Subsequence
http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html
*/

class Solution
{
public:
#define MANACHER
#ifndef MANACHER
	string longestPalindrome(string s)	// enumerate method
	{
		string result;
		for (int pos = 0; pos < s.length(); pos++)
		{
			// enumerate all odd length palindrome
			int odd = 0;
			while ((pos >= odd) && ((pos + odd) < s.length()) && (s[pos - odd] == s[pos + odd]))
			{
				odd++;
			}
			if (result.length() < (odd + odd - 1))
			{
				result = s.substr(pos - odd + 1, odd + odd - 1);
			}
			// enumerate all even length palindrome
			int even = 0;
			while ((pos >= even) && ((pos + even + 1) < s.length()) && (s[pos - even] == s[pos + even + 1]))
			{
				even++;
			}
			if (result.length() < (even + even))
			{
				result = s.substr(pos - even + 1, even + even);
			}
		}
		return result;
	}
#else
	string longestPalindrome(string s)	// manacher algorithm
	{
		string supers;
		for (int i = 0; i < s.length(); i++)
		{
			supers += '|';
			supers += s[i];
		}
		supers += '|';
		cout << supers << '\n';

		int RmaxI = 0, RmaxPos = 0;
		int *map = new int[supers.length()];
		for (int i = 0; i < supers.length(); i++)
		{
			map[i] = 0;
			if (i <= RmaxPos)
			{
				int i_mirror = RmaxI - (i - RmaxI);
				map[i] = min(RmaxPos - i, map[i_mirror]);
			}
			// palindrome expand from position i
			while ((map[i] <= i) && ((i + map[i]) < supers.length()) && (supers[i - map[i]] == supers[i + map[i]]))
			{
				map[i]++;
			}
			map[i]--;
			if (RmaxPos < (i + map[i]))
			{
				RmaxPos = i + map[i];
				RmaxI = i;
			}
		}
		int ansI = 0, ansLen = 0;
		for (int i = 0; i < supers.length(); i++)
		{
			if (ansLen < map[i])
			{
				ansLen = map[i];
				ansI = i;
				cout << ansI << '\t' << ansLen << '\n';
			}
		}
		delete []map;
		return s.substr((ansI - ansLen) >> 1, ansLen);
	}
#endif
};

/*
idea: enumerate every possible odd & even length palindrome
	famous manacher's algorithm: http://blog.csdn.net/han_xiaoyang/article/details/11969497#t20
complexity: O(N^2), manacher O(N)
*/

int main(void)
{
	string s("bananas");
	Solution engine;
	cout << engine.longestPalindrome(s) << '\n';
	return 0;
}
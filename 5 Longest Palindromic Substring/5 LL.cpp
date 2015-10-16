#include <vector>
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
	string longestPalindrome(string s)
	{
		vector<char> super((s.size() << 1) + 1, ' ');
		for (int i = 1; i < super.size(); i += 2)
		{
			super[i] = s[i >> 1];
		}
		int RmaxI = 0, RmaxPos = 0, ansI = 0;
		vector<int> map(super.size(), 0);
		for (int i = 1; i < map.size(); ++i)
		{
			if (i <= RmaxPos)
			{
				map[i] = min(RmaxPos - i, map[RmaxI - i + RmaxI]);
			}
			while ((i > map[i]) && ((i + map[i] + 1) < map.size()) && (super[i - map[i] - 1] == super[i + map[i] + 1]))
			{
				++map[i];
			}
			if (RmaxPos < (i + map[i]))
			{
				RmaxPos = i + map[i];
				RmaxI = i;
			}
			if (map[ansI] < map[i])
			{
				ansI = i;
			}
		}
		return s.substr((ansI - map[ansI]) >> 1, map[ansI]);
	}
};

/*
idea: famous manacher's algorithm: http://blog.csdn.net/han_xiaoyang/article/details/11969497#t20
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.longestPalindrome("bananas") << '\n';
	return 0;
}
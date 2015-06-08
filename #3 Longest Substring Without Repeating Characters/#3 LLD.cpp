#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution
{
public:
#define FORWARD
#ifndef FORWARD
	int lengthOfLongestSubstring(string s)  // reverse order
	{
		int laterPosition[256]; // record char later position in s
		for (int i = 255; i >= 0; i--)
		{
			laterPosition[i] = s.length();
		}
		int *unrepeatlen = new int[s.length()];
		for (int i = s.length() - 1; i >= 0; i--)
		{
			unrepeatlen[i] = laterPosition[(unsigned int)s[i]] - i;
			laterPosition[(unsigned int)s[i]] = i;
		}
		int result = 0;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			int nowlen = unrepeatlen[i];
			for (int j = 1; j < nowlen; j++)
			{
				if (nowlen > (unrepeatlen[i + j] + j))
				{
					nowlen = unrepeatlen[i + j] + j;
				}
			}
			result = (nowlen > result) ? nowlen : result;
		}
		delete []unrepeatlen;
		return result;
	}
#else
	int lengthOfLongestSubstring(string s)  // forward order, faster
	{
		int prePosition[256];   // record char previous position in s
		for (int i = 255; i >= 0; i--)
		{
			prePosition[i] = -1;
		}
		int nowlen = 0, result = 0;
		for (int i = 0; i < s.length(); i++)
		{
			nowlen++;
			int unrepeatlen = i - prePosition[(unsigned int)s[i]];
			prePosition[(unsigned int)s[i]] = i;
			if (nowlen > unrepeatlen)   // limit to char s[i]
			{
				nowlen = unrepeatlen;
			}
			result = (nowlen > result) ? nowlen : result;
		}
		return result;
	}
#endif
};

/*
idea: unrepeatlen only consider same char, double for take care other chars between two same char
complexity: reverse O(N * result), forward O(N)
*/

int main(void)
{
	string s = "abcabcbb";
	Solution engine;
	cout << engine.lengthOfLongestSubstring(s) << '\n';
	return 0;
}
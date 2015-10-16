#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution
{
public:
	void reverseWords(string &s)
	{
		string::iterator data = s.begin();
		string::iterator push = data;
		bool loop = true;
		while (loop)
		{
			while (push[0] != ' ')
			{
				++push;
				if (push == s.end())
				{
					loop = false;
					break;
				}
			}
			string::iterator swap = push - 1;
			while (data < swap)
			{
				char cache = data[0];
				data[0] = swap[0];
				swap[0] = cache;
				++data;
				--swap;
			}
			data = push + 1;
			push = data;
		}
	}
};

/*
idea: scan space and reverse
complexity: Time O(N)
*/

int main(void)
{
	string s = "the sky is blue";
	Solution engine;
	engine.reverseWords(s);
	return 0;
}
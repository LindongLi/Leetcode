#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/isomorphic-strings/

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution
{
private:
	char map[128];
	char revmap[128];
public:
	bool isIsomorphic(string s, string t)
	{
		string::iterator sdata = s.begin();
		string::iterator tdata = t.begin();
		for (; sdata != s.end(); ++sdata, ++tdata)
		{
			char rd = map[size_t(sdata[0])];
			if (rd != '\0')	// has map
			{
				if (rd != tdata[0]) return false;
			}
			else
			{
				rd = revmap[size_t(tdata[0])];
				if ((rd != '\0') && (rd != sdata[0]))
				{
					return false;	// already mapped
				}
				map[size_t(sdata[0])] = tdata[0];
				revmap[size_t(tdata[0])] = sdata[0];
			}
		}
		return true;
	}
};

/*
idea: map check, revmap prevent multi-to-one link
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isIsomorphic("ab", "aa") << '\n';
	return 0;
}
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/valid-anagram/

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		int alphabets[26] = {0};
		string::iterator data = s.begin();
		for (; data != s.end(); ++data)
		{
			++alphabets[int(data[0] - 'a')];
		}
		data = t.begin();
		for (; data != t.end(); ++data)
		{
			--alphabets[int(data[0] - 'a')];
		}
		for (int i = 0; i < 26; ++i)
		{
			if (alphabets[i] != 0) return false;
		}
		return true;
	}
};

/*
idea: count alphabet occur times
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isAnagram("anagram", "nagaram") << '\n';
	return 0;
}
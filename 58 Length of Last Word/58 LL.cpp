#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/length-of-last-word/

Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int result = 0;
		string::iterator data = s.end() - 1;
		while ((data >= s.begin()) && (data[0] == ' '))
		{
			--data;	// skip space after
		}
		for (; data >= s.begin(); --data)
		{
			if (data[0] == ' ') break;
			++result;
		}
		return result;
	}
};

/*
idea: reverse iterator
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.lengthOfLastWord("abc def") << '\n';
	return 0;
}
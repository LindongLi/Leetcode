#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/valid-palindrome/

Given a string, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

class Solution
{
private:
	static bool alphanumeric(char &c)
	{
		if (('a' <= c) && (c <= 'z'))
		{
			c += 'A' - 'a';
			return true;
		}
		if (('A' <= c) && (c <= 'Z'))
		{
			return true;
		}
		if (('0' <= c) && (c <= '9'))
		{
			return true;
		}
		return false;
	}
public:
	bool isPalindrome(string s)
	{
		string::iterator min = s.begin();
		string::iterator max = s.end() - 1;
		while (min < max)
		{
			if (!alphanumeric(min[0]))
			{
				++min;
				continue;
			}
			if (!alphanumeric(max[0]))
			{
				--max;
				continue;
			}
			if (min[0] != max[0]) return false;
			++min;
			--max;
		}
		return true;
	}
};

/*
idea: two iterator squeeze
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isPalindrome("A man, a plan, a canal: Panama") << '\n';
	return 0;
}
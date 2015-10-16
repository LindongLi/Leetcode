#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution
{
public:
	bool isValid(string s)
	{
		vector<char> stack(1, '*');
		string::iterator data = s.begin();
		for (; data != s.end(); ++data)
		{
			switch (data[0])
			{
			case '(':
			case '{':
			case '[':
				stack.push_back(data[0]);
				break;
			case ')':
				if (stack.back() != '(') return false;
				stack.pop_back();
				break;
			case '}':
				if (stack.back() != '{') return false;
				stack.pop_back();
				break;
			case ']':
				if (stack.back() != '[') return false;
				stack.pop_back();
				break;
			default:
				return false;
			}
		}
		return (stack.size() == 1);
	}
};

/*
idea: using stack to remember pairs
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isValid("([{}])") << '\n';
	return 0;
}
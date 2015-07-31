#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()",
which has length = 4.
*/

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int result = 0;
		vector<int>score;
		vector<char>stack;
		string::iterator data = s.begin();
		for (; data != s.end(); ++data)
		{
			if (data[0] == '(')
			{
				stack.push_back(data[0]);
				continue;
			}
			if ((data[0] == ')') && (stack.size() != 0) && (stack.back() == '('))
			{
				stack.pop_back();
				if ((stack.size() != 0) && (stack.back() == '*'))
				{
					score.back() += 2;
				}
				else
				{
					score.push_back(2);
					stack.push_back('*');
				}
				result = max(result, score.back());
			}
		}
		return result;
	}
};

/*
idea: using stack to remember pairs
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.longestValidParentheses("()(())") << '\n';
	return 0;
}
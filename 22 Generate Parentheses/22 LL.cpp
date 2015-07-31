#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution
{
private:
	vector<string> result;
	void search(string answer, int left, int right)
	{
		if (right == 0)
		{
			result.push_back(answer);
		}
		else
		{
			if (left > 0)
			{
				search(answer + '(', left - 1, right);
			}
			if (left < right)
			{
				search(answer + ')', left, right - 1);
			}
		}
	}
public:
	vector<string> generateParenthesis(int n)
	{
		search("", n, n);
		return result;
	}
};

/*
idea: could be left or right parentheses
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.generateParenthesis(3).size() << '\n';
	return 0;
}
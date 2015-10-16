#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		vector<int> stack;
		vector<string>::iterator data = tokens.begin();
		for (int cache; data != tokens.end(); ++data)
		{
			if (data[0] == "+")
			{
				cache = stack.back();
				stack.pop_back();
				stack.back() += cache;
				continue;
			}
			if (data[0] == "-")
			{
				cache = stack.back();
				stack.pop_back();
				stack.back() -= cache;
				continue;
			}
			if (data[0] == "*")
			{
				cache = stack.back();
				stack.pop_back();
				stack.back() *= cache;
				continue;
			}
			if (data[0] == "/")
			{
				cache = stack.back();
				stack.pop_back();
				stack.back() /= cache;
				continue;
			}
			stack.push_back(stoi(data[0]));
		}
		return stack.back();
	}
};

/*
idea: process every operation
complexity: Time O(N)
*/

int main(void)
{
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	Solution engine;
	cout << engine.evalRPN(tokens) << '\n';
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/multiply-strings/

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution
{
private:
	string multiply(string &rvb, int digit, int zeros = 0)
	{
		int carry = 0;
		string rvanswer(zeros, '0');
		string::iterator data = rvb.begin();
		for (; data != rvb.end(); ++data)
		{
			carry += int(data[0] - '0') * digit;
			rvanswer += char('0' + carry % 10);
			carry /= 10;
		}
		if (carry != 0) rvanswer += char('0' + carry);
		while ((rvanswer.size() != 0) && (rvanswer.back() == '0'))
		{
			rvanswer.pop_back();
		}
		return rvanswer;
	}
	void addtoself(string &rvanswer, string &rvb)
	{
		int carry = 0;
		string::iterator data = rvanswer.begin();
		string::iterator adder = rvb.begin();
		for (; data != rvanswer.end(); ++data)
		{
			carry += int(data[0] - '0');
			if (adder != rvb.end())
			{
				carry += int(adder[0] - '0');
				++adder;
			}
			if (carry >= 10)
			{
				data[0] = char('0' + carry - 10);
				carry = 1;
			}
			else
			{
				data[0] = char('0' + carry);
				carry = 0;
			}
		}
		for (; adder != rvb.end(); ++adder)
		{
			carry += int(adder[0] - '0');
			if (carry >= 10)
			{
				rvanswer += char('0' + carry - 10);
				carry = 1;
			}
			else
			{
				rvanswer += char('0' + carry);
				carry = 0;
			}
		}
		if (carry != 0) rvanswer += char('0' + carry);
		if (rvanswer.length() == 0) rvanswer = "0";
	}
public:
	string multiply(string num1, string num2)
	{
		string result;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < num2.length(); i++)
		{
			string part = multiply(num1, num2[i] - '0', i);
			addtoself(result, part);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

/*
idea: simulate hand multiply
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.multiply("123", "11") << '\n';
	return 0;
}
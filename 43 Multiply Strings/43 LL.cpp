#include <vector>
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
	void selfadding(string &rvanswer, string &rvb)
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
	}
public:
	string multiply(string num1, string num2)
	{
		string result = "0";
		if ((num1 == "") || (num1 == "0") || (num2 == "") || (num2 == "0"))
		{
			return result;
		}
		if (num1.size() < num2.size())
		{
			num1.swap(num2);
		}
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		vector<string> multable(9, num1);
		for (int i = 1; i < multable.size(); ++i)
		{
			selfadding(multable[i], multable[i - 1]);
		}
		string zeros;
		for (int i = 0; i < num2.length(); i++)
		{
			if (num2[i] != '0')
			{
				zeros += multable[int(num2[i] - '1')];
				selfadding(result, zeros);
			}
			zeros.resize(i + 1);
			zeros[i] = '0';
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
	cout << engine.multiply("123", "999999999999999999999") << '\n';
	return 0;
}
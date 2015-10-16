#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/fraction-to-recurring-decimal/

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution
{
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		long long int a = numerator, b = denominator;
		bool negative = false;
		if (a <= 0)
		{
			if (a == 0) return "0";
			negative = !negative;
			a = -a;
		}
		if (b <= 0)
		{
			if (b == 0) return "ERROR";
			negative = !negative;
			b = -b;
		}
		string result = negative ? "-" : "";
		result += to_string(a / b);	a %= b;
		if (a == 0) return result;
		result.push_back('.');
		// using map to record remainder
		unordered_map<long long int, int> map;
		int repeating_pos = -1;
		while (a != 0)
		{
			if (map.find(a) != map.end())
			{
				repeating_pos = map[a];
				break;
			}
			map[a] = result.size();
			// calculate next bit
			a *= 10;
			result += to_string(a / b);	a %= b;
		}
		if (repeating_pos != -1)
		{
			result.insert(repeating_pos, "(");
			result.push_back(')');
		}
		return result;
	}
};

/*
idea: mimic hand calculating
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.fractionToDecimal(1, 8123) << '\n';
	return 0;
}
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/integer-to-roman/

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution
{
private:
	static string fill(int num, const char *alpha)
	{
		string answer;
		if (num == 9)
		{
			answer += alpha[0];
			answer += alpha[2];
		}
		else if (num == 4)
		{
			answer += alpha[1];
			answer += alpha[2];
		}
		else
		{
			if (num >= 5)
			{
				num -= 5;
				answer += alpha[1];
			}
			if (num >= 1)
			{
				answer += alpha[2];
				if (num >= 2)
				{
					answer += alpha[2];
					if (num >= 3)
					{
						answer += alpha[2];
					}
				}
			}
		}
		return answer;
	}
public:
	string intToRoman(int num)
	{
		string result;
		result += fill((num / 1000) % 10, "  M");
		result += fill((num / 100) % 10, "MDC");
		result += fill((num / 10) % 10, "CLX");
		result += fill(num % 10, "XVI");
		return result;
	}
};

/*
idea: 4 and 9 special cases
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.intToRoman(1207) << '\n';
	return 0;
}
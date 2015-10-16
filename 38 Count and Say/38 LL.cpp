#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/count-and-say/

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution
{
private:
	string speak(string src)
	{
		string answer;
		int count = 1;
		char lastval = src[0];
		string::iterator data = src.begin() + 1;
		for (; data !=  src.end(); ++data)
		{
			if (lastval == data[0]) ++count;
			else
			{
				answer += char('0' + count);
				answer += lastval;
				lastval = data[0];
				count = 1;
			}
		}
		answer += char('0' + count);
		answer += lastval;
		return answer;
	}
public:
	string countAndSay(int n)
	{
		string result = "1";
		while (--n > 0)
		{
			result = speak(result);
		}
		return result;
	}
};

/*
idea: count-and-say procedure
complexity: Time O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.countAndSay(9) << '\n';
	return 0;
}
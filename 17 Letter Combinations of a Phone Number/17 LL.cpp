#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		static const string map[] =
		{
			"abc", "def", "ghi", "jkl",
			"mno", "pqrs", "tuv", "wxyz"
		};
		vector<string> result(1, "");
		string::iterator data = digits.begin();
		for (; data != digits.end(); ++data)
		{
			if ((data[0] < '2') || (data[0] > '9'))
			{
				continue;
			}
			const string &exd = map[int(data[0] - '2')];
			int nowsize = result.size();
			result.resize(nowsize * exd.size());
			for (int i = 1, pos = nowsize; i < exd.size(); ++i)
			{
				for (int j = 0; j < nowsize; ++j)
				{
					result[pos++] = result[j] + exd[i];
				}
			}
			for (int j = 0; j < nowsize; ++j)
			{
				result[j] += exd[0];
			}
		}
		return (result.size() == 1) ? vector<string>() : result;
	}
};

/*
idea: depth first construct
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.letterCombinations("23").size() << '\n';
	return 0;
}
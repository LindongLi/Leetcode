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
private:
	string answer;
	vector<string> result;
	void search(string::iterator data, int pos = 0)
	{
		static const string map[] =
		{
			" ", "abc", "def",
			"ghi", "jkl", "mno",
			"pqrs", "tuv", "wxyz"
		};
		if (('0' < data[pos]) && (data[pos] <= '9'))
		{
			answer.resize(pos + 1);
			int index = int(data[pos] - '1');
			for (int n = 0; n < map[index].length(); ++n)
			{
				answer[pos] = map[index][n];
				search(data, pos + 1);
			}
		}
		else if ((data[pos] == '\0') && (answer.length() != 0))
		{
			result.push_back(answer);
		}
	}
public:
	vector<string> letterCombinations(string digits)
	{
		search(digits.begin());
		return result;
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
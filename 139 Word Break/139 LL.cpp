#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution
{
private:
	string::iterator data;
	bool search(unordered_set<string>& dict, int min, int max)
	{
		if (min > max) return true;
		for (int i = min; i <= max; ++i)
		{
			if (dict.find(string(data + min, data + i + 1)) != dict.end())
			{
				if (search(dict, i + 1, max)) return true;
			}
		}
		return false;
	}
public:
	bool wordBreak(string s, unordered_set<string>& wordDict)
	{
		vector<bool> map(s.size() + 1, false);
		map[0] = true;	// set initialization
		for (int i = 1; i <= s.size(); ++i)
		{

		}
		data = s.begin();
		return search(wordDict, 0, s.size() - 1);
	}
};

/*
idea: depth first search
complexity: Time O(N)
*/

int main(void)
{
	unordered_set<string> wordDict;
	wordDict.insert("leet");
	wordDict.insert("code");
	Solution engine;
	cout << engine.wordBreak("leetcode", wordDict) << '\n';
	return 0;
}
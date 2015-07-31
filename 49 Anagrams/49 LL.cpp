#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
https://leetcode.com/problems/anagrams/

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution
{
public:
	vector<string> anagrams(vector<string>& strs)
	{
		vector<string> result;
		unordered_set<string> dict;
		unordered_set<string> anadict;
		vector<string>::iterator data = strs.begin();
		for (; data != strs.end(); ++data)
		{
			string clone = data[0];
			sort(clone.begin(), clone.end());
			if (dict.find(clone) == dict.end())
			{
				dict.insert(clone);
			}
			else anadict.insert(clone);	// appear twice, is anagram
		}
		for (; data != strs.begin(); --data)
		{
			string clone = data[-1];
			sort(clone.begin(), clone.end());
			if (anadict.find(clone) != anadict.end())
			{
				result.push_back(data[-1]);
			}
		}
		return result;
	}
};

/*
idea: scan remember anagrams, scan again and pick them
complexity: Time O(N)
*/

int main(void)
{
	vector<string> strs;
	strs.push_back("tea");
	strs.push_back("and");
	strs.push_back("ate");
	strs.push_back("eat");
	strs.push_back("den");
	Solution engine;
	cout << engine.anagrams(strs).size() << '\n';
	return 0;
}
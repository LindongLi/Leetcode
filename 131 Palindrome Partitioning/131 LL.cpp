#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution
{
private:
	vector<string> trace;
	string::iterator data;
	vector<vector<string> > result;
	bool ispartition(int min, int max)
	{
		while (min < max)
		{
			if (data[min] != data[max])
			{
				return false;
			}
			++min;
			--max;
		}
		return true;
	}
	void search(int min, int max)
	{
		if (min <= max)
		{
			for (int i = min; i <= max; ++i)
			{
				if (!ispartition(min, i)) continue;
				trace.push_back(string(data + min, data + i + 1));
				search(i + 1, max);
				trace.pop_back();
			}
		}
		else
		{
			result.push_back(trace);
		}
	}
public:
	vector<vector<string> > partition(string s)
	{
		data = s.begin();
		search(0, s.length() - 1);
		return result;
	}
};

/*
idea: depth first search, list all possible combinations
complexity: Time O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.partition("aab").size() << '\n';
	return 0;
}
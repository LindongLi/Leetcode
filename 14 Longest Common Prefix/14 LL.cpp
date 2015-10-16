#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string result;
		if (strs.size() == 0)
		{
			return result;
		}
		int len = 0;
		while (len != strs[0].size())
		{
			char c = strs[0][len];
			for (int i = 1; i < strs.size(); ++i)
			{
				if ((len == strs[i].size()) || (strs[i][len] != c))
				{
					return result;
				}
			}
			result += c;
			++len;
		}
		return result;
	}
};

/*
idea: loop among strings
complexity: O(N^2)
*/

int main(void)
{
	vector<string> strs;
	strs.push_back("abcd");
	strs.push_back("abde");
	strs.push_back("abef");
	Solution engine;
	cout << engine.longestCommonPrefix(strs) << '\n';
	return 0;
}
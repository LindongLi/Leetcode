#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/palindrome-partitioning-ii/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution
{
private:
	int result;
	string::iterator data;
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
	void search(int min, int max, int part)
	{
		if (min <= max)
		{
			if (part >= result) return;
			for (int i = max; i >= min; --i)
			{
				if (!ispartition(min, i)) continue;
				search(i + 1, max, part + 1);
			}
		}
		else
		{
			result = ::min(result, part);
		}
	}
public:
	int minCut(string s)
	{
		data = s.begin();
		result = s.length();
		search(0, s.length() - 1, 0);
		return result - 1;
	}
};

/*
idea: depth first search, list all possible combinations
complexity: Time O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/edit-distance/

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		vector<vector<int> > map(2, vector<int>(word1.length()));
		for (int i = 0; i < word1.size(); ++i)
		{
			if (word1[i] == word2[0])
			{
				map[i] = i;
			}
			else
			{
				map[i] = min(map[i - 1] + 1, i + 1);
			}
		}
		int switch = 0;
	for (int i = 1; i < word2.size(); ++i)
		{
			switch = 1 - switch ;
		for (int j = )
			}
	}
};

/*
idea: typical dynamic programming
complexity: Time O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.minDistance("123", "2") << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/edit-distance/

Given two words word1 and word2,
find the minimum number of steps required to convert word1 to word2.
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
		vector<int> opt(word2.length() + 1);
		for (int i = 0; i < opt.size(); ++i)
		{
			opt[i] = i;
		}
		string::iterator data = word1.begin();
		for (; data != word1.end(); ++data)
		{
			++opt[0];
			vector<int>::iterator it = opt.begin() + 1;
			string::iterator scan = word2.begin();
			for (; scan != word2.end(); ++scan, ++it)
			{
				it[0] = min(it[0], it[-1]) + ((data[0] == scan[0]) ? 0 : 1);
				cout << it[0] << '\t';
			}
			cout << endl;
		}
		return opt.back();
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
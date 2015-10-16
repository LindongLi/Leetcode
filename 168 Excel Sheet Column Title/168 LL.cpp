#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/excel-sheet-column-title/

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
*/

class Solution
{
public:
	string convertToTitle(int n)
	{
		string revans;
		while (n > 0)
		{
			--n;	// set A to 0
			revans += 'A' + (n % 26);
			n /= 26;
		}
		return string(revans.rbegin(), revans.rend());
	}
};

/*
idea: similar to integer to string
complexity: Time O(logN)
*/

int main(void)
{
	Solution engine;
	cout << engine.convertToTitle(702) << '\n';
	return 0;
}
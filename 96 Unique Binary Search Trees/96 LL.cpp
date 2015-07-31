#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/unique-binary-search-trees/

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3
*/

class Solution
{
public:
	int numTrees(int n)
	{
		int i = 2;
		vector<int> map(n + 1, 0);
		for (map[0] = map[1] = 1; i <= n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				map[i] += map[j] * map[i - j - 1];
			}
		}
		return map.back();
	}
};

/*
idea: dynamic programing
complexity: O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.numTrees(3) << '\n';
	return 0;
}
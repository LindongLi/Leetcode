#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/combinations/

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution
{
private:
	vector<int> trace;
	vector<vector<int> > result;
	void search(int min, int max, int pick)
	{
		if (pick == 0)
		{
			result.push_back(trace);
		}
		else
		{
			if ((max - min) < (pick - 1)) return;
			search(min + 1, max, pick);
			trace.push_back(min);
			search(min + 1, max, pick - 1);
			trace.pop_back();
		}
	}
public:
	vector<vector<int> > combine(int n, int k)
	{
		search(1, n, k);
		return result;
	}
};

/*
idea: depth first search
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.combine(4, 2).size() << '\n';
	return 0;
}
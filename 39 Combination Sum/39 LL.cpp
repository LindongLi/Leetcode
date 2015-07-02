#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

class Solution
{
private:
	vector<int>::iterator data;
	vector<vector<int> > result;
	void search(int max, int target, vector<int> &trace)
	{
		if (target == 0)
		{
			// remember to reverse for non-descending
			result.push_back(vector<int> (trace.rbegin(), trace.rend()));
		}
		else if (max >= 0)
		{
			int i = 0;
			for (; target >= (i * data[max]); ++i)
			{
				search(max - 1, target - (i * data[max]), trace);
				trace.push_back(data[max]);
			}
			trace.erase(trace.end() - i, trace.end());
		}
	}
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target)
	{
		vector<int> trace;
		data = candidates.begin();
		sort(candidates.begin(), candidates.end());
		search(candidates.size() - 1, target, trace);
		return result;
	}
};

/*
idea: depth first search
complexity: Time O(N * target)
*/

int main(void)
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	Solution engine;
	cout << engine.combinationSum(candidates, 7).size() << '\n';
	return 0;
}
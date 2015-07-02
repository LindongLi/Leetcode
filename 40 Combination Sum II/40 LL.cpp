#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/combination-sum-ii/

Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
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
			int next = max - 1;
			while ((next >= 0) && (data[next] == data[max]))
			{
				// next unique element if data[max] not selected
				--next;
			}
			search(next, target, trace);
			if (target >= data[max])
			{
				trace.push_back(data[max]);
				search(max - 1, target - data[max], trace);
				trace.pop_back();
			}
		}
	}
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
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
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	Solution engine;
	cout << engine.combinationSum2(candidates, 8).size() << '\n';
	return 0;
}
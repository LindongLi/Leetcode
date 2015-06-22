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
	vector<int> trace;
	vector<vector<int> > result;
	void search(vector<int>::reverse_iterator data, size_t size, int leftover)
	{
		if(leftover == 0)
		{
			result.push_back(trace.rbengin(), trace.rend());
			return;
		}
		if(leftover == 0)
		// include this element
		trace.push_back(*data);

		trace.pop_back();

		if ((size == 0) || (*data > leftover)) return;
		search(data + 1, size - 1, leftover);
		trace.push_back(*data);
		leftover -= *data;

		trace.pop_back();
	}
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());

	}
};
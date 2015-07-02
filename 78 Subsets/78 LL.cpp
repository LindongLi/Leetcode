#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution
{
private:
	vector<int>::iterator data;
	vector<vector<int> > result;
	void search(vector<int> &trace, int max)
	{
		if (max < 0) result.push_back(trace);
		else
		{
			trace.push_back(data[max]);
			search(trace, max - 1);
			trace.pop_back();
			search(trace, max - 1);
		}
	}
public:
	vector<vector<int> > subsets(vector<int>& nums)
	{
		// sort from big to small
		sort(nums.rbegin(), nums.rend());
		data = nums.begin();
		vector<int> trace;
		search(trace, nums.size() - 1);
		return result;
	}
};

/*
idea: binary search all possible combinations
complexity: Time O(2^N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	Solution engine;
	cout << engine.subsets(nums).size() << '\n';
	return 0;
}
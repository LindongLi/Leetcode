#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/subsets-ii/

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
			// discard the element, move to next unique value
			int lastval = data[max];
			do
			{
				--max;
			}
			while ((max >= 0) && (lastval == data[max]));
			search(trace, max);
		}
	}
public:
	vector<vector<int> > subsetsWithDup(vector<int>& nums)
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
	nums.push_back(2);
	Solution engine;
	cout << engine.subsetsWithDup(nums).size() << '\n';
	return 0;
}
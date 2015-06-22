#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/search-for-a-range/

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution
{
private:
	int want;
	vector<int> *pnums;
	int search(int l, int r, bool top)
	{
		if (r <= (l + 1))
		{
			if (top)
			{
				if (want == (*pnums)[l]) return l;
				if (want == (*pnums)[r]) return r;
			}
			else
			{
				if (want == (*pnums)[r]) return r;
				if (want == (*pnums)[l]) return l;
			}
			return -1;
		}
		int mid = (l + r) >> 1;
		if ((want < (*pnums)[mid]) || (top && (want == (*pnums)[mid])))
		{
			return search(l, mid, top);
		}
		else
		{
			return search(mid, r, top);
		}
	}
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> result(2, -1);
		want = target;
		pnums = &nums;
		if (nums.size() != 0)
		{
			result[0] = search(0, nums.size() - 1, true);
			result[1] = search(0, nums.size() - 1, false);
		}
		return result;
	}
};

/*
idea: binary search
complexity: Time O(logN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(10);
	Solution engine;
	cout << engine.searchRange(nums, 8).size() << '\n';
	return 0;
}
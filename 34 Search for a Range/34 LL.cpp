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
	vector<int>::iterator data;
	int searchStt(int target, int min, int max)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (target <= data[mid])
			{
				max = mid;
			}
			else
			{
				min = mid + 1;
			}
		}
		if (target == data[min]) return min;
		if (target == data[max]) return max;
		return -1;
	}
	int searchEnd(int target, int min, int max)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (target < data[mid])
			{
				max = mid - 1;
			}
			else
			{
				min = mid;
			}
		}
		if (target == data[max]) return max;
		if (target == data[min]) return min;
		return -1;
	}
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		data = nums.begin();
		vector<int> result(2, -1);
		if (nums.size() != 0)
		{
			result[0] = searchStt(target, 0, nums.size() - 1);
			result[1] = searchEnd(target, 0, nums.size() - 1);
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
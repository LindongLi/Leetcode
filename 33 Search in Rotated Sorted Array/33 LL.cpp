#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search.
If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution
{
private:
	vector<int>::iterator data;
	int binarysearch(int target, int min, int max)
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
	int findgap(int min, int max)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			// no duplicate
			if (data[min] < data[mid])
			{
				min = mid;
			}
			else
			{
				max = mid;
			}
		}
		return min;
	}
public:
	int search(vector<int>& nums, int target)
	{
		if (nums.size() == 0) return -1;
		data = nums.begin();
		int min = 0, max = nums.size() - 1;
		// only one element in array or no gap
		if ((min == max) || (data[min] < data[max]))
		{
			return binarysearch(target, min, max);
		}
		int gap = findgap(min, max);
		if (data[min] <= target)
		{
			return binarysearch(target, min, gap);
		}
		return binarysearch(target, gap + 1, max);
	}
};

/*
idea: find the rotate pivot first, then binary search
complexity: Time O(logN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	Solution engine;
	cout << engine.search(nums, 0) << '\n';
	return 0;
}
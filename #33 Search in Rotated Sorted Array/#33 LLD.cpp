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
	vector<int>::iterator data;
private:
	int binarysearch(int stt, int end, int target)
	{
		if (end <= (stt + 1))
		{
			if (data[stt] == target) return stt;
			if (data[end] == target) return end;
			return -1;
		}
		int mid = (stt + end) >> 1;
		if (target <= data[mid])
		{
			return binarysearch(stt, mid, target);
		}
		return binarysearch(mid + 1, end, target);
	}
	int findgap(int stt, int end)
	{
		if (end <= (stt + 1)) return stt;
		int mid = (stt + end) >> 1;
		// no duplicate
		if (data[stt] < data[mid])
		{
			return findgap(mid, end);
		}
		return findgap(stt, mid);
	}
public:
	int search(vector<int>& nums, int target)
	{
		int stt = 0;
		int end = nums.size() - 1;
		if (end < 0) return -1;
		data = nums.begin();
		// only one element in array
		if ((stt == end) || (data[stt] < data[end]))
		{
			return binarysearch(stt, end, target);
		}
		int gap = findgap(stt, end);
		if (data[stt] <= target)
		{
			return binarysearch(stt, gap, target);
		}
		return binarysearch(gap + 1, end, target);
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
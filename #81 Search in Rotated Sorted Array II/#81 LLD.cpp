#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Follow up for "Search in Rotated Sorted Array (#33)":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution
{
	vector<int>::iterator data;
private:
	bool binarysearch(int stt, int end, int target)
	{
		if (end <= (stt + 1))
		{
			if (data[stt] == target) return true;
			if (data[end] == target) return true;
			return false;
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
		if (data[stt] < data[mid])
		{
			return findgap(mid, end);
		}
		if (data[stt] > data[mid])
		{
			return findgap(stt, mid);
		}
		// duplicate occurs
		while ((stt != mid) && (data[stt] == data[mid]))
		{
			stt++;
		}
		if (stt == mid) return findgap(mid, end);
		if (data[stt] < data[mid]) return stt - 1;
		return findgap(stt, mid);
	}
public:
	bool search(vector<int>& nums, int target)
	{
		int stt = 0;
		int end = nums.size() - 1;
		if (end < 0) return false;
		data = nums.begin();
		// guess no gap
		if (binarysearch(stt, end, target))
		{
			return true;
		}
		if (stt != end)
		{
			int gap = findgap(stt, end);
			if (data[stt] <= target)
			{
				return binarysearch(stt, gap, target);
			}
			return binarysearch(gap + 1, end, target);
		}
		return false;
	}
};

/*
idea: find the rotate pivot first, then binary search
complexity: Time O(N) worst
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	Solution engine;
	cout << engine.search(nums, 0) << '\n';
	return 0;
}
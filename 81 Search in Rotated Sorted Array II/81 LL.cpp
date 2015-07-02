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
private:
	vector<int>::iterator data;
	bool binarysearch(int target, int min, int max)
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
		if (target == data[min]) return true;
		if (target == data[max]) return true;
		return false;
	}
	int findgap(int min, int max)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (data[min] < data[mid])
			{
				min = mid;
			}
			else if (data[min] > data[mid])
			{
				max = mid;
			}
			else	// duplicate occurs
			{
				while ((min != mid) && (data[min] == data[mid]))
				{
					++min;
				}
				if (min != mid)
				{
					if (data[min] < data[mid]) return min - 1;
					max = mid;	// data[min] > data[mid]
				}
			}
		}
		return min;
	}
public:
	bool search(vector<int>& nums, int target)
	{
		if (nums.size() == 0) return false;
		data = nums.begin();
		int min = 0, max = nums.size() - 1;
		// guess no gap try search
		if (binarysearch(target, min, max))
		{
			return true;
		}
		if (min != max)
		{
			int gap = findgap(min, max);
			if (data[min] <= target)
			{
				return binarysearch(target, min, gap);
			}
			return binarysearch(target, gap + 1, max);
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
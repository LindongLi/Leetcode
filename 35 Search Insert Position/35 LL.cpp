#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/search-insert-position/

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int min = 0, max = nums.size() - 1;
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (target <= nums[mid])
			{
				max = mid;
			}
			else
			{
				min = mid + 1;
			}
		}
		// careful in underflow and overflow cases
		if (target <= nums[min]) return min;
		if (target <= nums[max]) return max;
		return max + 1;
	}
};

/*
idea: binary search
complexity: Time O(logN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	Solution engine;
	cout << engine.searchInsert(nums, 7) << '\n';
	return 0;
}
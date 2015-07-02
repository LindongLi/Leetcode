#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution
{
private:
	vector<int>::iterator data;
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
	int findMin(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		data = nums.begin();
		int min = 0, max = nums.size() - 1;
		// only one element in array or no gap
		if ((min == max) || (data[min] < data[max]))
		{
			return data[min];
		}
		return data[findgap(min, max) + 1];
	}
};

/*
idea: find the rotate pivot first, element after the pivot should be minimum
complexity: Time O(logN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.findMin(nums) << '\n';
	return 0;
}
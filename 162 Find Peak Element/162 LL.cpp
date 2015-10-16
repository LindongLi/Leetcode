#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/find-peak-element/

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

class Solution
{
private:
	vector<int>::iterator data;
	int search(int min, int max)
	{
		while ((min + 3) < max)	// 4 elements at least
		{
			int mid = (min + max) >> 1;
			int mid_1 = mid + 1;
			if (data[mid] < data[mid_1])
			{
				min = mid;
			}
			else
			{
				max = mid_1;
			}
		}
		return (data[min + 1] > data[max - 1]) ? (min + 1) : (max - 1);
	}
public:
	int findPeakElement(vector<int>& nums)
	{
		int min = 0, max = nums.size() - 1;
		if (min == max) return 0;
		data = nums.begin();
		if (data[min] > data[min + 1]) return min;
		if (data[max - 1] < data[max]) return max;
		return search(min, max);
	}
};

/*
idea: binary search
complexity: O(logN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	Solution engine;
	cout << engine.findPeakElement(nums) << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Follow up for "Find Minimum in Rotated Sorted Array (#153)":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
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
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.findMin(nums) << '\n';
	return 0;
}
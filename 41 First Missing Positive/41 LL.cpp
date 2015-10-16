#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/first-missing-positive/

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution
{
public:
	int firstMissingPositive(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			while ((0 < nums[i]) && (nums[i] != (i + 1)) && (nums[i] <= nums.size()))
			{
				int cache = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				if (cache == nums[i]) break;	// prevent infinity loop
				nums[i] = cache;
			}
		}
		int reslut = 0;
		for (; reslut < nums.size(); ++reslut)
		{
			if (nums[reslut] != (reslut + 1))
			{
				break;
			}
		}
		return reslut + 1;
	}
};

/*
idea: put number to corresponding order position
complexity: Time O(N * target)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	Solution engine;
	cout << engine.firstMissingPositive(nums) << '\n';
	return 0;
}
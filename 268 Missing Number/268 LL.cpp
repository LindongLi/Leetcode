#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/missing-number/

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant extra space complexity?
*/

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		nums.push_back(-1);
		for (int i = 0; i < nums.size(); ++i)
		{
			while ((nums[i] >= 0) && (nums[i] != i))
			{
				int cache = nums[nums[i]];
				nums[nums[i]] = nums[i];
				nums[i] = cache;
			}
		}
		int result = 0;
		for (; result < nums.size(); ++result)
		{
			if (nums[result] < 0) break;
		}
		return result;
	}
};

/*
idea: put number in coherent position
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(3);
	Solution engine;
	cout << engine.missingNumber(nums) << '\n';
	return 0;
}
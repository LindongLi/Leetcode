#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that
adjacent houses have security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution
{
public:
	int rob(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		// attention position 2 adjust
		if (nums.size() >= 2)
		{
			nums[1] = max(nums[0], nums[1]);
		}
		vector<int>::iterator data = nums.begin() + 2;
		for (; data < nums.end(); ++data)
		{
			data[0] = max(data[-1], data[0] + data[-2]);
		}
		return nums.rbegin()[0];
	}
};

/*
idea: dynamic programing, OPT(n) optimal solution having n house to choose
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.rob(nums) << '\n';
	return 0;
}
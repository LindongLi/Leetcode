#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/3sum-closest/

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int i, j, k, want;
		int result = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			j = i + 1;
			k = nums.size() - 1;
			want = target - nums[i];
			while (j < k)	// O(N) progressive try
			{
				if (abs(want - (nums[j] + nums[k])) < abs(target - result))
				{
					// better result
					result = nums[i] + nums[j] + nums[k];
				}
				if ((nums[j] + nums[k]) < want)
				{
					j++;
				}
				else if ((nums[j] + nums[k]) > want)
				{
					k--;
				}
				else return target;
			}
		}
		return result;
	}
};

/*
idea: sort and loop
complexity: Time O(N^2)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-4);
	Solution engine;
	cout << engine.threeSumClosest(nums, 1) << '\n';
	return 0;
}
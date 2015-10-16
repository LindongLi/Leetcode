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
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());
		int result = nums[0] + nums[1] + nums[2];
		vector<int>::iterator first = nums.begin();
		int val_first = ~first[0];	// memorize
		for (; first != nums.end(); ++first)
		{
			// remove duplicate
			if (val_first == first[0]) continue;
			val_first = first[0];
			vector<int>::iterator second = first + 1;
			vector<int>::iterator third = nums.end() - 1;
			// typical two slide pointer
			while (second < third)
			{
				int attempt = val_first + second[0] + third[0];
				if (abs(target - attempt) < abs(target - result))
				{
					// better result
					result = attempt;
				}
				if (attempt < target)
				{
					++second;
				}
				else if (attempt == target)
				{
					return target;
				}
				else
				{
					--third;
				}
			}
		}
		return result;
	}
};

/*
idea: loop first value, slide two additional values.
complexity: Time O(N^2) Space O(1)
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
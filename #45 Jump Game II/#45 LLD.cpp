#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/jump-game-ii/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution
{
public:
	int jump(vector<int>& nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		vector<int> map(size, 0x7FFFFFFF);
		map[0] = 0;
		for (int i = 0; i < size; ++i)
		{
			for (int j = min(i + nums[i], size - 1); j > 0; --j)
			{
				// reverse order accelerating
				if (map[j] <= (map[i] + 1)) break;
				map[j] = map[i] + 1;
			}
		}
		return map[size - 1];
	}
};

/*
idea: dynamic programming
complexity: Time O(N^2)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	Solution engine;
	cout << engine.jump(nums) << '\n';
	return 0;
}
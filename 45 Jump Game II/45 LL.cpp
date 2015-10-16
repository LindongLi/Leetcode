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
		if (nums.size() < 2) return 0;
		vector<int> maps(nums.size(), 0x7FFFFFFF);
		vector<int>::iterator here = maps.begin();
		vector<int>::iterator go = nums.begin();
		for (here[0] = 0; (here + go[0]) < (maps.end() - 1); ++here, ++go)
		{
			// go to next step from here, until reach last index
			vector<int>::iterator next = here + go[0];
			for (; next != here; --next)
			{
				if (next[0] <= (here[0] + 1))
				{
					break;	// accelerate
				}
				next[0] = here[0] + 1;
			}
		}
		return here[0] + 1;	// input is empty
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
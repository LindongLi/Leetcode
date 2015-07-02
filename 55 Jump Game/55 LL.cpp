#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/jump-game/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		if (nums.size() < 2) return true;
		vector<int>::iterator here = nums.begin();
		vector<int>::iterator reachable = here + 1;
		for (; here < reachable; ++here)
		{
			if (reachable < (here + here[0] + 1))
			{
				reachable = here + here[0] + 1;
				if (reachable >= nums.end())
				{
					return true;
				}
			}
		}
		return false;
	}
};

/*
idea: loop and revise reachable position
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(2);
	Solution engine;
	cout << engine.canJump(nums) << '\n';
	return 0;
}
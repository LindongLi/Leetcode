#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three times except for one.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?
*/

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int higher = 0, lower = 0;
		vector<int>::iterator data = nums.begin();
		for (; data != nums.end(); ++data)
		{
			higher |= lower & data[0];
			lower ^= data[0];
			int cache = higher & lower;
			// clear 11 to 00, ternary
			higher ^= cache;
			lower ^= cache;
		}
		return lower;
	}
};

/*
idea: mimic ternary notation bits counting
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(9);
	nums.push_back(2);
	nums.push_back(2);
	Solution engine;
	cout << engine.singleNumber(nums) << '\n';
	return 0;
}
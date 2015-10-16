#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/single-number/

Given an array of integers, every element appears twice except for one.
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
		int result = 0;
		vector<int>::iterator data = nums.begin();
		for (; data != nums.end(); ++data)
		{
			result ^= data[0];
		}
		return result;
	}
};

/*
idea: number XOR itself is zero
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	Solution engine;
	cout << engine.singleNumber(nums) << '\n';
	return 0;
}
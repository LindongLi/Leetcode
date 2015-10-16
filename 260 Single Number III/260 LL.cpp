#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/single-number-iii/

Given an array of numbers nums,
in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant space complexity?
*/

class Solution
{
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		int answer = 0;
		vector<int>::iterator data = nums.begin();
		for (; data != nums.end(); ++data)
		{
			answer ^= data[0];
		}
		// get last different bit
		int mask = ((answer ^ (answer - 1)) >> 1) + 1;
		vector<int> result(2);
		data = nums.begin();
		for (; data != nums.end(); ++data)
		{
			if ((data[0] & mask) == 0)
			{
				result[0] ^= data[0];
			}
			else
			{
				result[1] ^= data[0];
			}
		}
		return result;
	}
};

/*
idea: group number in two category base on last different bit
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(3);
	Solution engine;
	cout << engine.singleNumber(nums).size() << '\n';
	return 0;
}
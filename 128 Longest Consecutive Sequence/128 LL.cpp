#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int result = 0;
		unordered_map<int, int> ftoe;	// map front to end
		unordered_map<int, int> etof;	// map end to front
		for (int i = 0; i < nums.size(); ++i)
		{
			if ((ftoe.find(nums[i]) != ftoe.end()) || (etof.find(nums[i]) != etof.end()))
			{
				continue;	// consecutive range already recorded
			}
			unordered_map<int, int>::iterator oldf = ftoe.find(nums[i] + 1);
			unordered_map<int, int>::iterator olde = etof.find(nums[i] - 1);
			if ((oldf != ftoe.end()) && (olde != etof.end()))
			{
				result = max(result, oldf->second - olde->second);
				ftoe[olde->second] = oldf->second;
				etof[oldf->second] = olde->second;
				ftoe.erase(oldf);
				etof.erase(olde);
				continue;
			}
			if (oldf != ftoe.end())
			{
				result = max(result, oldf->second - nums[i]);
				ftoe[nums[i]] = oldf->second;
				etof[oldf->second] = nums[i];
				ftoe.erase(oldf);
				continue;
			}
			if (olde != etof.end())
			{
				result = max(result, nums[i] - olde->second);
				ftoe[olde->second] = nums[i];
				etof[nums[i]] = olde->second;
				etof.erase(olde);
				continue;
			}
			ftoe[nums[i]] = nums[i];
			etof[nums[i]] = nums[i];
		}
		return result + 1;
	}
};

/*
idea: front to end & end to front map maintain consecutive range
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(-7);
	nums.push_back(-1);
	nums.push_back(3);
	nums.push_back(-9);
	nums.push_back(-4);
	nums.push_back(7);
	nums.push_back(-3);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(9);
	nums.push_back(4);
	nums.push_back(5);
	Solution engine;
	cout << engine.longestConsecutive(nums) << '\n';
	return 0;
}
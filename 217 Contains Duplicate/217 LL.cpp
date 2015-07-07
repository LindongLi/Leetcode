#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/contains-duplicate/

Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.
*/

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		if (nums.size() < 2) return false;
		sort(nums.begin(), nums.end());
		vector<int>::iterator data = nums.begin() + 1;
		for (; data != nums.end(); ++data)
		{
			if (data[-1] == data[0]) return true;
		}
		return false;
	}
};

/*
idea: sort and loop every possible
complexity: O(NlogN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.containsDuplicate(nums) << '\n';
	return 0;
}
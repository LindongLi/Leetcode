#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/contains-duplicate-ii/

Given an array of integers and an integer k,
find out whether there there are two distinct indices i and j in the array
such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_map<int, int> val_index;	// map value to index
		for (int i = 0; i < nums.size(); ++i)
		{
			if (val_index.find(nums[i]) != val_index.end())	// found
			{
				if ((i - val_index[nums[i]]) <= k) return true;
			}
			val_index[nums[i]] = i;
		}
		return false;
	}
};

/*
idea: unordered_map remember last position
complexity: O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.containsNearbyDuplicate(nums, 1) << '\n';
	return 0;
}
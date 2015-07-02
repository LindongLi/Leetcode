#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/two-sum/

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2
*/

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		unordered_map<int, int> val_index;	// map value to index
		for (int i = 0; i < nums.size(); ++i)
		{
			if (val_index.find(target - nums[i]) != val_index.end())	// found
			{
				result.push_back(val_index[target - nums[i]]);
				result.push_back(i + 1);
				break;
			}
			else
			{
				val_index[nums[i]] = i + 1;
			}
		}
		return result;
	}
};

/*
idea: unordered_map uses hash? Searching costs constant time?
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(0);
	Solution engine;
	cout << engine.twoSum(nums, 0).size() << '\n';
	return 0;
}
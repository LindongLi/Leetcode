#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/summary-ranges/

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution
{
public:
	vector<string> summaryRanges(vector<int>& nums)
	{
		vector<string> result;
		if (nums.size() == 0) return result;
		int last_val = nums[0];
		vector<int>::iterator data = nums.begin() + 1;
		for (; data != nums.end(); ++data)
		{
			if ((data[-1] + 1) != data[0])
			{
				string cache = to_string(last_val);
				if (last_val != data[-1])
				{
					cache += "->";
					cache += to_string(data[-1]);
				}
				result.push_back(cache);
				last_val = data[0];
			}
		}
		string cache = to_string(last_val);
		if (last_val != data[-1])
		{
			cache += "->";
			cache += to_string(data[-1]);
		}
		result.push_back(cache);
		return result;
	}
};

/*
idea: loop and construct
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(3);
	Solution engine;
	engine.summaryRanges(nums);
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates (#26)":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
It doesn't matter what you leave beyond the new length.
*/

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		int result = 1;
		int current = nums[0], times = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (current != nums[i])
			{
				current = nums[i];
				times = 1;	// reset count
				nums[result++] = current;
			}
			else if (times < 2)
			{
				++times;
				nums[result++] = current;
			}
		}
		return result;
	}
};

/*
idea: read & write position indexes
complexity: O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	Solution engine;
	cout << engine.removeDuplicates(nums) << '\n';
	return 0;
}
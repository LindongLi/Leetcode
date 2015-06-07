#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array, remove the duplicates in place such that
each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int result = 0;
		int current = (nums.size() != 0) ? !nums[0] : 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(current != nums[i])
			{
				current = nums[i];
				nums[result++] = current;
			}
		}
		return result;
	}
};

/*
idea: two position indexes
complexity: O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.removeDuplicates(nums) << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (val != nums[i])
			{
				nums[result++] = nums[i];
			}
		}
		return result;
	}
};

/*
idea: loop each element
complexity: O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.removeElement(nums, 1) << '\n';
	return 0;
}
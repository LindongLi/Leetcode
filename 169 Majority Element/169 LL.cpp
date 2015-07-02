#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Moore’s Voting Algorithm.
Basic idea of the algorithm is if we cancel out each occurrence of an element e
with all the other elements that are different from e then e will exist till end if it is a majority element.
*/

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int maj_index = 0, count = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[maj_index] == nums[i])
			{
				count++;
			}
			else
			{
				count--;
				if (count == 0)	// caution! ONLY candidate
				{
					maj_index = i;
					count = 1;
				}
			}
		}
		// second step: check candidate, since majority always exists, this step is unnecessary
		return nums[maj_index];
	}
};

/*
idea: moore's voting algorithm
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(4);
	Solution engine;
	cout << engine.majorityElement(nums) << '\n';
	return 0;
}
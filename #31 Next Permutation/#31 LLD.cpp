#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int swipos = nums.size() - 1, i;
		for (i = swipos; i > 0; i--)
		{
			if (nums[i - 1] < nums[i])
			{
				swipos = i;	// careful reset swipos
				int swival = nums[i];
				for (int j = i; j < nums.size(); j++)
				{
					if ((nums[i - 1] < nums[j]) && (nums[j] < swival))
					{
						swipos = j;
						swival = nums[j];
					}
				}
				break;
			}
		}
		if (i == 0)
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		int cache = nums[i - 1];
		nums[i - 1] = nums[swipos];
		nums[swipos] = cache;
		sort(nums.begin() + i, nums.end());
	}
};

/*
idea: find the first decrease element
complexity: O(NlogN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	Solution engine;
	engine.nextPermutation(nums);
	cout << nums[0] << nums[1] << nums[2] << '\n';
	return 0;
}
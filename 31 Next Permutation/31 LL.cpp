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
		if (nums.size() == 0) return;
		vector<int>::iterator data = nums.end() - 1;
		for (; data != nums.begin(); --data)
		{
			if (data[-1] < data[0])
			{
				vector<int>::iterator bigger = data;
				vector<int>::iterator slides = data + 1;
				// find slightly bigger element after rising
				for (; slides != nums.end(); ++slides)
				{
					if ((data[-1] < slides[0]) && (slides[0] < bigger[0]))
					{
						bigger = slides;
					}
				}
				swap(data[-1], bigger[0]);
				sort(data, nums.end());
				return;
			}
		}
		// full decline
		reverse(nums.begin(), nums.end());
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
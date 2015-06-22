#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container,
such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int result = 0;
		int left = 0, right = height.size() - 1;
		while (left < right)
		{
			int area = (right - left) * min(height[left], height[right]);
			result = (result < area) ? area : result;
			if (height[left] < height[right])
			{
				// when left is the the bottleneck, right-- will definitely decrease capacity
				// while left++ could possible increase capacity
				left++;
			}
			else right--;
		}
		// assume [i, j] is optimal solution, if left reaches i first, and j <= right
		// then next step must be right--, else height[i] < height[right]
		// [i, right] solution will be better than [i, j] solution
		return result;
	}
};

/*
idea: min-max pointers clipping, prove as note
complexity: O(N)
*/

int main(void)
{
	vector<int> height;
	height.push_back(1);
	height.push_back(2);
	height.push_back(13);
	height.push_back(14);
	height.push_back(5);
	height.push_back(6);
	Solution engine;
	cout << engine.maxArea(height) << '\n';
	return 0;
}
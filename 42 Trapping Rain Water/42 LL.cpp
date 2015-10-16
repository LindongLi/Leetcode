#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution
{
public:
	int trap(vector<int>& height)
	{
		if (height.size() <= 2) return 0;
		// processing left boundary
		vector<int> leftpos;
		vector<int> leftheight;
		for (int i = 0, max = 0; i < height.size(); ++i)
		{
			if (max < height[i])
			{
				max = height[i];
				leftpos.push_back(i);
				leftheight.push_back(max);
			}
		}
		// processing right boundary
		vector<int> rightpos;
		vector<int> rightheight;
		for (int i = height.size() - 1, max = 0; i >= 0; --i)
		{
			if (max < height[i])
			{
				max = height[i];
				rightpos.push_back(i);
				rightheight.push_back(max);
			}
		}
		// calculating area
		int result = 0;
		for (int i = 1; i < leftpos.size(); ++i)
		{
			result += (leftpos[i] - leftpos[i - 1]) * leftheight[i - 1];
		}
		// append max height area, attention minus 1 width adjust
		rightpos.push_back(leftpos[leftpos.size() - 1] - 1);
		for (int i = 1; i < rightpos.size(); ++i)
		{
			result += (rightpos[i - 1] - rightpos[i]) * rightheight[i - 1];
		}
		for (int i = 0; i < height.size(); ++i)
		{
			// minus bar area
			result -= height[i];
		}
		return result;
	}
};

/*
idea: project and produce left & right boundary graph, combine(and) two graphs then minus bar area
complexity: O(N)
*/

int main(void)
{
	vector<int> height;
	height.push_back(0);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(1);
	Solution engine;
	cout << engine.trap(height) << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/largest-rectangle-in-histogram/

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution
{
private:
	int result;
	vector<int> hstack;
	vector<int> istack;	// index stack
	void maxArea(int height, int index)
	{
		int i = hstack.size() - 1;
		for (; i >= 0; --i)
		{
			if (hstack[i] >= height)
			{
				hstack.pop_back();
				istack.pop_back();
			}
			else break;
		}
		if (i >= 0)
		{
			result = max(result, height * ())
		}
		if (hstack.size() != 0)
		{
			area = height * (position - pstack.back());
		}
		hstack.push_back(height);
		pstack.push_back(position);
		return area;
	}
public:
	int largestRectangleArea(vector<int>& height)
	{
		int result = 0;
		for (int i = 0; i < height.size(); ++i)
		{
			result = max(result, maxArea(height[i], i));
		}
		return result;
	}
};

/*
idea: https://en.wikipedia.org/wiki/All_nearest_smaller_values#Sequential_algorithm
complexity: O(logN)
*/

int main(void)
{
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);
	Solution engine;
	cout << engine.largestRectangleArea(height) << '\n';
	return 0;
}
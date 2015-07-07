#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

class Solution
{
private:
	static void swap(int &a, int &b)
	{
		int cache = a;
		a = b;
		b = cache;
	}
public:
	void sortColors(vector<int>& nums)
	{
		vector<int>::iterator red = nums.begin();
		vector<int>::iterator data = red;
		vector<int>::iterator blue = nums.end() - 1;
		while ((red <= data) && (data <= blue))
		{
			if (data[0] == 0)	// red
			{
				swap(red[0], data[0]);
				while ((red <= blue) && (red[0] == 0))
				{
					++red;
				}
				if (red > data) data = red;
			}
			else if (data[0] == 2)	// blue
			{
				swap(data[0], blue[0]);
				while ((red <= blue) && (blue[0] == 2))
				{
					--blue;
				}
			}
			else ++data;
		}
	}
};

/*
idea: loop while swap values
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	Solution engine;
	engine.sortColors(nums);
	return 0;
}
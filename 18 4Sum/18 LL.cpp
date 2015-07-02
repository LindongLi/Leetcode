#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/4sum/

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/

class Solution
{
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target)
	{
		vector<vector<int> > result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());
		vector<int>::iterator first = nums.begin();
		int firval = first[0] - 1;
		for (; first != nums.end(); ++first)
		{
			// remove duplicate
			if (first[0] == firval) continue;
			firval = first[0];
			vector<int>::iterator second = first + 1;
			int secval = second[0] - 1;
			for (; second != nums.end(); ++second)
			{
				// remove duplicate
				if (second[0] == secval) continue;
				secval = second[0];
				int want = target - firval - secval;
				vector<int>::iterator third = second + 1;
				vector<int>::iterator fourth = nums.end() - 1;
				// typical two slide pointer
				while (third < fourth)
				{
					if ((third[0] + fourth[0]) < want)
					{
						++third;
					}
					else if ((third[0] + fourth[0]) > want)
					{
						--fourth;
					}
					else
					{
						vector<int> quadruplet(4);
						quadruplet[0] = first[0];
						quadruplet[1] = second[0];
						quadruplet[2] = third[0];
						quadruplet[3] = fourth[0];
						result.push_back(quadruplet);
						// pointer slide required!
						while ((third < fourth) && (third[0] == quadruplet[2]))
						{
							++third;
						}
					}
				}
			}
		}
		return result;
	}
};

/*
idea: loop first & second value, slide two additional values.
complexity: Time O(N^3)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(2);
	Solution engine;
	cout << engine.fourSum(nums, 0).size() << '\n';
	return 0;
}
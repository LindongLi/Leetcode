#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

class Solution
{
public:
	vector<vector<int> > threeSum(vector<int>& nums)
	{
		vector<int> answer(3);
		vector<vector<int> > result;
		if (nums.size() < 3) return result;
		sort(nums.begin(), nums.end());
		vector<int>::iterator first = nums.begin();
		int firval = first[0] - 1;
		for (; first != nums.end(); ++first)
		{
			// remove duplicate
			if (first[0] == firval) continue;
			firval = first[0];
			int want = 0 - first[0];
			vector<int>::iterator second = first + 1;
			vector<int>::iterator third = nums.end() - 1;
			// typical two slide pointer
			while (second < third)
			{
				if ((second[0] + third[0]) < want)
				{
					++second;
				}
				else if ((second[0] + third[0]) > want)
				{
					--third;
				}
				else
				{
					answer[0] = first[0];
					answer[1] = second[0];
					answer[2] = third[0];
					result.push_back(answer);
					// pointer slide required!
					int secval = second[0];
					while ((second < third) && (second[0] == secval))
					{
						++second;
					}
				}
			}
		}
		return result;
	}
};

/*
idea: loop first value, slide two additional values.
complexity: Time O(N^2)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	Solution engine;
	cout << engine.threeSum(nums).size() << '\n';
	return 0;
}
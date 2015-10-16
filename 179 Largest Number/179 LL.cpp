#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution
{
private:
	static bool compare(int a, int b)
	{
		long long int da = 10, db = 10;
		while (a >= da)
		{
			da *= 10;
		}
		while (b >= db)
		{
			db *= 10;
		}
		return (double(a) / double(da - 1)) > (double(b) / double(db - 1));
	}
public:
	string largestNumber(vector<int>& nums)
	{
		string result;
		sort(nums.begin(), nums.end(), Solution::compare);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (result == "0")
			{
				result = to_string(nums[i]);
			}
			else result += to_string(nums[i]);
		}
		return result;
	}
};

/*
idea: consider int as decimal, special sort algorithm
complexity: Time O(NlogN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(121);
	nums.push_back(12);
	Solution engine;
	cout << engine.largestNumber(nums) << '\n';
	return 0;
}
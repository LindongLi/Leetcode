#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		int result = nums[0];
		vector<int>::iterator data = nums.begin() + 1;
		for (; data != nums.end(); ++data)
		{
			data[0] = max(data[0], data[-1] + data[0]);
			result = max(result, data[0]);
		}
		return result;
	}
};

/*
idea: dynamic programing, OPT(n) optimal solution which includes nums[n]
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	Solution engine;
	cout << engine.maxSubArray(nums) << '\n';
	return 0;
}
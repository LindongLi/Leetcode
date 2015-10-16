#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/maximum-product-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		int result = nums[0];
		vector<int> minimal(nums.size());
		vector<int>::iterator max = nums.begin() + 1;
		vector<int>::iterator min = minimal.begin() + 1;
		for (min[-1] = max[-1]; max != nums.end(); ++max, ++min)
		{
			if (max[0] >= 0)
			{
				min[0] = ::min(max[0], min[-1] * max[0]);
				max[0] = ::max(max[0], max[-1] * max[0]);
			}
			else
			{
				min[0] = ::min(max[0], max[-1] * max[0]);
				max[0] = ::max(max[0], min[-1] * max[0]);
			}
			result = ::max(result, max[0]);
		}
		return result;
	}
};

/*
idea: dynamic programing, tracing min optimal too because of negative value
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(-4);
	nums.push_back(-3);
	nums.push_back(-2);
	Solution engine;
	cout << engine.maxProduct(nums) << '\n';
	return 0;
}
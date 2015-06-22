#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution
{
private:
	vector<int> *pnums;
	int findDiv(int left, int right)
	{
		if (right <= (left + 1))
		{
			return min((*pnums)[left], (*pnums)[right]);
		}
		int mid = (left + right) >> 1;
		if ((*pnums)[left] < (*pnums)[mid])
		{
			return findDiv(mid, right);
		}
		else
		{
			return findDiv(left, mid);
		}
	}
public:
	int findMin(vector<int>& nums)
	{
		pnums = &nums;
		return findDiv(0, nums.size() - 1);
	}
};

/*
idea: divide & conquer
complexity: Time O(logN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(3);
	Solution engine;
	cout << engine.findMin(nums) << '\n';
	return 0;
}
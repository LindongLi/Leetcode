#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n)
to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		for (int i = m - 1; i >= 0; i--)	// right shift elements
		{
			nums1[i + n] = nums1[i];
		}
		int mi = n, ni = 0, pos = 0;
		while ((mi != (m + n)) && (ni != n))
		{
			if (nums1[mi] < nums2[ni])
			{
				nums1[pos++] = nums1[mi++];
			}
			else
			{
				nums1[pos++] = nums2[ni++];
			}
		}
		while (ni != n)
		{
			nums1[pos++] = nums2[ni++];
		}
	}
};

/*
idea: linear time merge
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(3);
	vector<int> nums2;
	nums2.push_back(2);
	Solution engine;
	engine.merge(nums1, 2, nums2, 1);
	return 0;
}
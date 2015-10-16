#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

class Solution
{
private:
	int findKth(vector<int>::iterator a, int lena, vector<int>::iterator b, int lenb, int k)
	{
		if (lena == 0) return b[k - 1];
		if (lenb == 0) return a[k - 1];
		if (k == 1) return min(a[0], b[0]);
		int posa = min(k >> 1, lena - 1);
		int posb = min(max(0, k - posa - 2), lenb - 1);
		posa = k - posb - 2;
		if (a[posa] <= b[posb])
		{
			if ((posa == lena - 1) || (b[posb] <= a[posa + 1]))
			{
				return b[posb];
			}
			return findKth(a + posa + 1, lena - posa - 1, b, lenb, k - posa - 1);
		}
		else
		{
			if ((posb == lenb - 1) || (a[posa] <= b[posb + 1]))
			{
				return a[posa];
			}
			return findKth(a, lena, b + posb + 1, lenb - posb - 1, k - posb - 1);
		}
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		double answer = 0;
		int total = nums1.size() + nums2.size();
		if (total != 0)
		{
			if ((total & 0x1) != 0)
			{
				answer += findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), (total + 1) >> 1);
			}
			else
			{
				answer += findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), total >> 1);
				answer += findKth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), (total >> 1) + 1);
				answer /= 2;
			}
		}
		return answer;
	}
};

/*
idea: http://articles.leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
complexity: O(logN)
*/

int main(void)
{
	vector<int> nums1;
	nums1.push_back(1);
	vector<int> nums2;
	nums2.push_back(2);
	Solution engine;
	cout << engine.findMedianSortedArrays(nums1, nums2) << '\n';
	return 0;
}
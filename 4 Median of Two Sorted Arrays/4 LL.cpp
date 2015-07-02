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
	int findkthsmall(vector<int>::iterator va, size_t a_size, vector<int>::iterator vb, size_t b_size, size_t k)
	{
		size_t a_pos = k >> 1;
		size_t b_pos = k - a_pos - 1;
		if (a_pos >= a_size)
		{
			a_pos = (a_size == 0) ? 0 : (a_size - 1);
			b_pos = k - a_pos - 1;
		}
		if (b_pos >= b_size)
		{
			b_pos = (b_size == 0) ? 0 : (b_size - 1);
			a_pos = k - b_pos - 1;
		}
		//cout << 'A' << a_size << '|' << a_pos << 'B' << b_size << '|' << b_pos << 'K' << k << '\n';
		if (((b_pos == 0) || (vb[b_pos - 1] <= va[a_pos])) && (va[a_pos] <= vb[b_pos]))
		{
			// va[a_pos] between vb[b_pos - 1] and vb[b_pos] then it should be k'th smallest
			return va[a_pos];
		}
		if (((a_pos == 0) || (va[a_pos - 1] <= vb[b_pos])) && (vb[b_pos] <= va[a_pos]))
		{
			// vb[b_pos] between va[a_pos - 1] and va[a_pos] then it should be k'th smallest
			return vb[b_pos];
		}
		if (va[a_pos] <= vb[b_pos])
		{
			// exclude va[0 - a_pos]
			++a_pos;
			a_size -= a_pos;
			k -= a_pos;
			if (a_size == 0)	// va lengh is zero
			{
				return vb[k - 1];
			}
			va += a_pos;
		}
		else
		{
			// exclude vb[0 - b_pos]
			++b_pos;
			b_size -= b_pos;
			k -= b_pos;
			if (b_size == 0)	// vb lengh is zero
			{
				return va[k - 1];
			}
			vb += b_pos;
		}
		return findkthsmall(va, a_size, vb, b_size, k);
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int maxflag;
		size_t la = nums1.size(), lb = nums2.size();
		if ((la == 0) && (lb == 0)) return 0;
		else if (la == 0) maxflag = nums2[lb - 1];
		else if (lb == 0) maxflag = nums1[la - 1];
		else maxflag = max(nums1[la - 1], nums2[lb - 1]);
		nums1.push_back(maxflag);
		nums2.push_back(maxflag);
		size_t mid = (la + lb) >> 1;
		if (((la + lb) & 0x1) != 0)
		{
			return findkthsmall(nums1.begin(), la, nums2.begin(), lb, mid + 1);
		}
		else
		{
			return (findkthsmall(nums1.begin(), la, nums2.begin(), lb, mid + 1) +
			        findkthsmall(nums1.begin(), la, nums2.begin(), lb, mid)) / 2.f;
		}
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
	nums2.push_back(3);
	Solution engine;
	cout << engine.findMedianSortedArrays(nums1, nums2) << '\n';
	return 0;
}
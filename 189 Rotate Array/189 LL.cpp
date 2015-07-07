#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/rotate-array/

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

class Solution
{
private:
	static int gcd(int a, int b)
	{
		if (b == 0) return 0;
		while (b != 0)
		{
			int tmp = a % b;
			a = b;
			b = tmp;
		}
		return a;
	}
public:
	void rotate(vector<int>& nums, int k)
	{
		int n = nums.size();
		if (n == 0) return;
		if (k >= n) k %= n;
		for (int cycle = gcd(n, k) - 1; cycle >= 0; --cycle)
		{
			int swift = cycle;
			int last_val = nums[cycle];
			while (1)
			{
				swift += k;
				if (swift >= n) swift -= n;
				if (swift == cycle) break;
				int cache = nums[swift];
				nums[swift] = last_val;
				last_val = cache;
			}
			nums[cycle] = last_val;
		}
	}
};

/*
idea: the cycles in rotation equals greatest common divisor of n and k
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	Solution engine;
	engine.rotate(nums, 1);
	return 0;
}
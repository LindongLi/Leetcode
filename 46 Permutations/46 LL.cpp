#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://leetcode.com/problems/permutations/

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution
{
private:
	vector<vector<int> > result;
	bool next(vector<int> &nums)
	{
		vector<int>::iterator data = nums.end() - 1;
		for (; data != nums.begin(); --data)
		{
			if (data[-1] < data[0])
			{
				vector<int>::iterator bigger = data;
				vector<int>::iterator slides = data + 1;
				// find slightly bigger element after rising
				for (; slides != nums.end(); ++slides)
				{
					if ((data[-1] < slides[0]) && (slides[0] < bigger[0]))
					{
						bigger = slides;
					}
				}
				swap(data[-1], bigger[0]);
				sort(data, nums.end());
				return true;
			}
		}
		// full decline
		return false;
	}
public:
	vector<vector<int> > permute(vector<int>& nums)
	{
		if (nums.size() <= 1)
		{
			if (nums.size() != 0)
			{
				result.push_back(nums);
			}
			return result;
		}
		sort(nums.begin(), nums.end());
		do
		{
			result.push_back(nums);
		}
		while (next(nums));
		return result;
	}
};

/*
idea: find the first decrease element
complexity: O(NlogN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	Solution engine;
	cout << engine.permute(nums).size() << '\n';
	return 0;
}
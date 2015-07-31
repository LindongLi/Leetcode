#include <vector>
#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an array where elements are sorted in ascending order,
convert it to a height balanced BST.
*/

class Solution
{
private:
	vector<int>::iterator data;
	TreeNode *search(int min, int max)
	{
		if (min > max) return NULL;
		int mid = min + ((max - min) >> 1);
		TreeNode *node = new TreeNode(data[mid]);
		node->left = search(min, mid - 1);
		node->right = search(mid + 1, max);
		return node;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		data = nums.begin();
		return search(0, nums.size() - 1);
	}
};

/*
idea: divide and conquer
complexity: Time O(N)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	Solution engine;
	cout << engine.sortedArrayToBST(nums) << '\n';
	return 0;
}
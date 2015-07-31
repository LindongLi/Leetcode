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
https://leetcode.com/problems/path-sum-ii/

Given a binary tree and a sum, find all root-to-leaf paths
where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

class Solution
{
private:
	vector<int> trace;
	vector<vector<int> > result;
	void search(TreeNode *root, int sum)
	{
		if (root == NULL) return;
		trace.push_back(root->val);
		if ((root->left == NULL) && (root->right == NULL))
		{
			if (sum == root->val)
			{
				result.push_back(trace);
			}
		}
		else
		{
			sum -= root->val;
			search(root->left, sum);
			search(root->right, sum);
		}
		trace.pop_back();
	}
public:
	vector<vector<int> > pathSum(TreeNode* root, int sum)
	{
		search(root, sum);
		return result;
	}
};

/*
idea: recursive, attention leaf has both NULL child
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.pathSum(NULL, 0).size() << '\n';
	return 0;
}
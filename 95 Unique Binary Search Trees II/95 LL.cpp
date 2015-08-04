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
https://leetcode.com/problems/unique-binary-search-trees-ii/

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3
*/

class Solution
{
private:
	void search(vector<TreeNode*> &trace, int min, int max)
	{
		trace.clear();	// clear for self usage
		if (min <= max)
		{
			vector<TreeNode*> left, right;
			vector<TreeNode*>::iterator il, ir;
			for (int mid = min; mid <= max; ++mid)
			{
				search(left, min, mid - 1);
				search(right, mid + 1, max);
				for (il = left.begin(); il != left.end(); ++il)
				{
					for (ir = right.begin(); ir != right.end(); ++ir)
					{
						trace.push_back(new TreeNode(mid));
						trace.back()->left = il[0];
						trace.back()->right = ir[0];
					}
				}
			}
		}
		else trace.push_back(NULL);
	}
public:
	vector<TreeNode*> generateTrees(int n)
	{
		vector<TreeNode*> result;
		search(result, 1, n);
		return result;
	}
};

/*
idea: recursive return vector of all possible branches
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.generateTrees(3).size() << '\n';
	return 0;
}
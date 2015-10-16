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
https://leetcode.com/problems/binary-tree-paths/

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

class Solution
{
private:
	vector<int> trace;
	vector<string> result;
	void search(TreeNode *node)
	{
		if (node == NULL) return;
		trace.push_back(node->val);
		if ((node->left == NULL) && (node->right == NULL))
		{
			string answer = to_string(trace[0]);
			vector<int>::iterator data = trace.begin() + 1;
			for (; data != trace.end(); ++data)
			{
				answer += "->" + to_string(data[0]);
			}
			result.push_back(answer);
		}
		else
		{
			search(node->left);
			search(node->right);
		}
		trace.pop_back();
	}
public:
	vector<string> binaryTreePaths(TreeNode* root)
	{
		search(root);
		return result;
	}
};

/*
idea: depth first search
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.binaryTreePaths(NULL).size() << '\n';
	return 0;
}
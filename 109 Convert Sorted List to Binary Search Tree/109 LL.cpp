#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.
*/

class Solution
{
private:
	ListNode *data;
	TreeNode *search(int min, int max)
	{
		if (min > max) return NULL;
		int mid = min + ((max - min) >> 1);
		TreeNode *left = search(min, mid - 1);
		TreeNode *node = new TreeNode(data->val);
		data = data->next;
		node->left = left;
		node->right = search(mid + 1, max);
		return node;
	}
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		data = head;
		int length = 0;
		while (head != NULL)
		{
			++length;
			head = head->next;
		}
		return search(0, length - 1);
	}
};

/*
idea: divide and conquer
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.sortedListToBST(NULL) << '\n';
	return 0;
}
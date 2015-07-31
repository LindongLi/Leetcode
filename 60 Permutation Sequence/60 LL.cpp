#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/permutation-sequence/

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution
{
private:
	vector<char> pool;
	vector<int> combine;
	void initialize(int n)
	{
		int base = 1;
		for (int i = 0; i < n; ++i)
		{
			base = base * (i + 1);
			pool.push_back(char('1' + i));
			combine.push_back(base);
		}
	}
	void pick(int pos, string &result)
	{
		result += pool[pos];
		pool.erase(pool.begin() + pos);
	}
public:
	string getPermutation(int n, int k)
	{
		initialize(n);
		string result;
		if ((k < 1) || (k > combine.back()))
		{
			return result;
		}
		else --k;	// index from 0
		for (int i = n - 2; i >= 0; --i)
		{
			pick(k / combine[i], result);
			k %= combine[i];
		}
		pick(0, result);
		return result;
	}
};

/*
idea: permutations count equals math combine
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.getPermutation(3, 4) << '\n';
	return 0;
}
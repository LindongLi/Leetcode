#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/gray-code/

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code,
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution
{
public:
	vector<int> grayCode(int n)
	{
		int max = unsigned(1) << n;
		vector<int> result(max);
		for (int i = 0; i < max; ++i)
		{
			result[i] = i ^ (i >> 1);
		}
		return result;
	}
};

/*
idea: https://en.wikipedia.org/wiki/Gray_code
complexity: O(2^N)
*/

int main(void)
{
	Solution engine;
	cout << engine.grayCode(2).size() << '\n';
	return 0;
}
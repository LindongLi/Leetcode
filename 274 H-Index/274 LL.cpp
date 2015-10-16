#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/h-index/

Given an array of citations (each citation is a non-negative integer) of a researcher,
write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each,
and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

class Solution
{
public:
	int hIndex(vector<int>& citations)
	{
		vector<int> trace(citations.size() + 1, 0);
		vector<int>::iterator data = citations.begin();
		for (; data != citations.end(); ++data)
		{
			int pos = max(0, int(citations.size()) - data[0]);
			++trace[pos];
		}
		data = trace.begin();
		int result = citations.size();
		for (int i = 0; data != trace.end(); ++data)
		{
			i += data[0];
			if (i >= result) break;
			--result;
		}
		return result;
	}
};

/*
idea: scan twice and count
complexity: Time O(N)
*/

int main(void)
{
	vector<int> citations;
	citations.push_back(3);
	citations.push_back(0);
	citations.push_back(6);
	citations.push_back(1);
	citations.push_back(5);
	Solution engine;
	cout << engine.hIndex(citations) << '\n';
	return 0;
}
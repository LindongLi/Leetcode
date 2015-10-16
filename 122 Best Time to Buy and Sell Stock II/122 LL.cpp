#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int result = 0;
		if (prices.size() < 2) return 0;
		vector<int>::iterator data = prices.begin() + 1;
		for (; data != prices.end(); ++data)
		{
			if (data[0] > data[-1])
			{
				result += (data[0] - data[-1]);
			}
		}
		return result;
	}
};

/*
idea: count every ascend interval
complexity: Time O(N)
*/

int main(void)
{
	vector<int> prices;
	prices.push_back(9);
	prices.push_back(1);
	prices.push_back(5);
	Solution engine;
	cout << engine.maxProfit(prices) << '\n';
	return 0;
}
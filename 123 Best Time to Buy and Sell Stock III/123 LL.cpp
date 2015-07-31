#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() < 2) return 0;
		vector<int> FirstTransaction(prices.size());
		vector<int> SecondTransaction(prices.size());
		// first transaction max profit
		int profit = 0;
		int minmaxval = prices[0];
		for (int i = 0; i < prices.size(); ++i)
		{
			if (prices[i] >= minmaxval)
			{
				profit = max(profit, prices[i] - minmaxval);
			}
			else minmaxval = prices[i];
			FirstTransaction[i] = profit;
		}
		// second transaction max profit
		profit = 0;
		minmaxval = prices[prices.size() - 1];
		for (int i = prices.size() - 1; i >= 0; --i)
		{
			if (minmaxval >= prices[i])
			{
				profit = max(profit, minmaxval - prices[i]);
			}
			else minmaxval = prices[i];
			SecondTransaction[i] = profit;
		}
		// try every two transactions combo
		profit = max(FirstTransaction.back(), SecondTransaction.front());
		for (int i = 1; i < prices.size(); ++i)
		{
			profit = max(profit, FirstTransaction[i - 1] + SecondTransaction[i]);
		}
		return profit;
	}
};

/*
idea: divide in two one transaction max profit problems
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
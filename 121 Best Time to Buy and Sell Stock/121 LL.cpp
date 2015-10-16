#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction
(ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit.
*/

class Solution
{
private:
	vector<int>::iterator data;
	void trace(int min, int max, int &low, int &high, int &profit)
	{
		// trace lowest & highest price, profit in [min, max]
		if (min != max)
		{
			int d_low[2], d_high[2], d_profit[2];
			// divide
			int mid = (min + max) >> 1;
			trace(min, mid, d_low[0], d_high[0], d_profit[0]);
			trace(mid + 1, max, d_low[1], d_high[1], d_profit[1]);
			// conquer
			low = ::min(d_low[0], d_low[1]);
			high = ::max(d_high[0], d_high[1]);
			profit = ::max(d_profit[0], d_profit[1]);
			if (profit < (d_high[1] - d_low[0]))
			{
				profit = d_high[1] - d_low[0];
			}
		}
		else
		{
			low = data[min];
			high = data[max];
			profit = 0;
		}
	}
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() < 2) return 0;
		data = prices.begin();
		int low, high, result;
		trace(0, prices.size() - 1, low, high, result);
		return result;
	}
};

/*
idea: typical divide & conquer
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
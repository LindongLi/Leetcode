#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/gas-station/

There are N gas stations along a circular route,
where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank
and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		if (gas.size() == 0) return -1;
		if (gas.size() == 1) return (gas[0] >= cost[0]) ? 0 : -1;
		for (int i = 0; i < gas.size(); ++i)
		{
			cost[i] = gas[i] - cost[i];
		}
		int start = 0, destination = 1, sum = cost[0];
		while ((start != destination) || (sum < 0))
		{
			if (sum < 0)
			{
				sum -= cost[start];
				if (++start == cost.size())
				{
					return -1;
				}
			}
			if (sum >= 0)
			{
				sum += cost[destination];
				if (++destination == cost.size())
				{
					destination = 0;
				}
			}
		}
		return start;
	}
};

/*
idea: slide start & end position sum
complexity: Time O(N)
*/

int main(void)
{
	vector<int> gas;
	gas.push_back(0);
	gas.push_back(4);
	vector<int> cost;
	cost.push_back(1);
	cost.push_back(4);
	Solution engine;
	cout << engine.canCompleteCircuit(gas, cost) << '\n';
	return 0;
}
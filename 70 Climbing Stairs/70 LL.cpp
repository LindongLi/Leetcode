#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
*/

class Solution
{
private:
	static int combination(int k, int n)
	{
		if (k > (n >> 1)) k = n - k;
		long long int answer = 1;
		for (int i = 0; i < k; ++i)
		{
			// attention overflow may occur
			answer = answer * (n - i) / (i + 1);
		}
		return (int)answer;
	}
public:
	int climbStairs(int n)
	{
		if (n <= 0) return 0;
		int result = 0;
		int ones = n, twos = 0;
		for (; ones >= 0; ++twos, ones -= 2)
		{
			result += combination(twos, twos + ones);
		}
		return result;
	}
};

/*
idea: list all one step & two step combination
complexity: O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.climbStairs(4) << '\n';
	return 0;
}
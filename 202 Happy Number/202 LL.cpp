#include <iostream>
#include <unordered_set>
using namespace std;

/*
https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution
{
private:
	int process(int n)
	{
		int answer = 0;
		while (n > 0)
		{
			register int cache = n % 10;
			n = n / 10;
			answer += cache * cache;
		}
		return answer;
	}
public:
	bool isHappy(int n)
	{
		unordered_set<int> searched;
		do
		{
			if (searched.find(n) != searched.end())	// cycle
			{
				return false;
			}
			searched.insert(n);
			n = process(n);
		}
		while (n != 1);
		return true;
	}
};

/*
idea: using set to detect endless cycle
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isHappy(19) << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/count-primes/

Description:
Count the number of prime numbers less than a non-negative number, n.
*/

class Solution
{
private:
	vector<int> primes;
public:
	int countPrimes(int n)
	{
		if (n <= 2) return 0;
		if (n == 3) return 1;
		primes.push_back(2);
		primes.push_back(3);
		int max_mul_index = 1;
		for (int num = 5, i; num < n; num += 2)
		{
			for (i = 1; i <= max_mul_index; ++i)
			{
				if ((num % primes[i]) == 0) break;
			}
			if (i > max_mul_index)
			{
				primes.push_back(num);
				if ((primes[max_mul_index] * primes[max_mul_index]) < num)
				{
					++max_mul_index;
				}
			}
		}
		return primes.size();
	}
};

/*
idea: list primes and use them as filter
complexity: O(N^2)
*/

int main(void)
{
	Solution engine;
	cout << engine.countPrimes(5) << '\n';
	return 0;
}
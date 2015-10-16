#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/plus-one/

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int carry = 1;
		vector<int>::reverse_iterator bit = digits.rbegin();
		for (; bit != digits.rend(); ++bit)
		{
			carry += bit[0];
			if (carry >= 10)
			{
				bit[0] = carry - 10;
				carry = 1;
			}
			else
			{
				bit[0] = carry;
				carry = 0;
			}
		}
		if (carry != 0)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

/*
idea: loop each element
complexity: O(N)
*/

int main(void)
{
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	Solution engine;
	cout << engine.plusOne(digits).size() << '\n';
	return 0;
}
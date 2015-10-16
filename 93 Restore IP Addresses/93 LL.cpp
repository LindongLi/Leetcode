#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/restore-ip-addresses/

Given a string containing only digits,
restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution
{
private:
	static bool checkfail(string &in)
	{
		return (stoi(in) > 255) || ((in.size() > 1) && (in[0] == '0'));
	}
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> result;
		int min = ::max(1, int(s.length()) - 9);
		int max = ::min(3, int(s.length()) - 3);
		for (int a = min; a <= max; ++a)
		{
			string sa = s.substr(0, a);
			if (checkfail(sa)) break;
			for (int b = min; b <= max; ++b)
			{
				string sb = s.substr(a, b);
				if (checkfail(sb)) break;
				for (int c = min; c <= max; ++c)
				{
					if ((a + b + c) >= s.length()) break;
					string sc = s.substr(a + b, c);
					if (checkfail(sc)) break;
					string sd = s.substr(a + b + c);
					if (checkfail(sd)) continue;
					cout << sa + '.' + sb + '.' + sc + '.' + sd << '\n';
					result.push_back(sa + '.' + sb + '.' + sc + '.' + sd);
				}
			}
		}
		return result;
	}
};

/*
idea: enumerate all dot positions
complexity: O(N^3)
*/

int main(void)
{
	Solution engine;
	engine.restoreIpAddresses("010010");
	return 0;
}
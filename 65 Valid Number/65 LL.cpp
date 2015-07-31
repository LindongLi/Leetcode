#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/valid-number/

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.
*/

class Solution
{
private:
	enum status
	{
		begin, sign, integer, dot,
		decimal, expt, exptsign,
		scientific, end
	};
	static bool notNumbit(char c)
	{
		return (c < '0') || (c > '9');
	}
public:
	bool isNumber(string s)
	{
		status flag = begin;
		string::iterator data = s.begin();
		for (; data < s.end(); ++data)
		{
			switch (flag)
			{
			case begin:
				if (notNumbit(data[0]))
				{
					switch (data[0])
					{
					case ' ':
						break;
					case '+':
					case '-':
						flag = sign;
						break;
					case '.':
						flag = dot;
						break;
					default:
						return false;
					}
				}
				else flag = integer;
				break;
			case sign:
				if (notNumbit(data[0]))
				{
					switch (data[0])
					{
					case '.':
						flag = dot;
						break;
					default:
						return false;
					}
				}
				else flag = integer;
				break;
			case integer:
				if (notNumbit(data[0]))
				{
					switch (data[0])
					{
					case ' ':
						flag = end;
						break;
					case '.':
						flag = decimal;
						break;
					case 'e':
						flag = expt;
						break;
					default:
						return false;
					}
				}
				break;
			case dot:
				if (notNumbit(data[0]))
				{
					return false;
				}
				else flag = decimal;
				break;
			case decimal:
				if (notNumbit(data[0]))
				{
					switch (data[0])
					{
					case ' ':
						flag = end;
						break;
					case 'e':
						flag = expt;
						break;
					default:
						return false;
					}
				}
				break;
			case expt:
				if (notNumbit(data[0]))
				{
					switch (data[0])
					{
					case '+':
					case '-':
						flag = exptsign;
						break;
					default:
						return false;
					}
				}
				else flag = scientific;
				break;
			case exptsign:
				if (notNumbit(data[0]))
				{
					return false;
				}
				else flag = scientific;
				break;
			case scientific:
				if (notNumbit(data[0]))
				{
					switch (data[0])
					{
					case ' ':
						flag = end;
						break;
					default:
						return false;
					}
				}
				break;
			default:
				if (data[0] != ' ') return false;
			}
		}
		return (flag == integer) || (flag == decimal) || (flag == scientific) || (flag == end);
	}
};

/*
idea: enumerate status machine
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.isNumber(" . ") << '\n';
	return 0;
}
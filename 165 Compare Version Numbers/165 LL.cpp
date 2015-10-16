#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/compare-version-numbers/

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three",
it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

class Solution
{
private:
	string::iterator read(string::iterator data, int &num)
	{
		num = 0;
		while ((data[0] >= '0') && (data[0] <= '9'))
		{
			num *= 10;
			num += int(data[0] - '0');
			++data;
		}
		if (data[0] == '.') ++data;
		return data;
	}
public:
	int compareVersion(string version1, string version2)
	{
		string::iterator it1 = version1.begin();
		string::iterator it2 = version2.begin();
		int nv1, nv2;
		do
		{
			it1 = read(it1, nv1);
			it2 = read(it2, nv2);
			if (nv1 > nv2) return 1;
			if (nv1 < nv2) return -1;
		}
		while ((it1 != version1.end()) || (it2 != version2.end()));
		return 0;
	}
};

/*
idea: compare split by dot
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.compareVersion("1.0.1", "1.1") << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/simplify-path/

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution
{
private:
	vector<string> trace;
public:
	string simplifyPath(string path)
	{
		path += '/';
		string::iterator data = path.begin();
		string::iterator slide = data;
		for (; slide != path.end(); ++slide)
		{
			if (slide[0] != '/') continue;
			string cur(data, slide);
			if ((cur != "") && (cur != "."))
			{
				if (cur == "..")
				{
					if (trace.size() != 0) trace.pop_back();
				}
				else
				{
					trace.push_back(cur);
				}
			}
			data = slide + 1;
		}
		string result;
		if (trace.size() == 0) return "/";
		vector<string>::iterator go = trace.begin();
		for (; go != trace.end(); ++go)
		{
			result += '/';
			result += go[0];
		}
		return result;
	}
};

/*
idea: split and process
complexity: Time O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.simplifyPath("/home//../") << '\n';
	return 0;
}
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
https://leetcode.com/problems/word-ladder-ii/

Given two words (start and end), and a dictionary,
find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
	["hit","hot","dot","dog","cog"],
	["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution
{
private:
	string target;
	vector<vector<string> > layer;
	vector<vector<string> > result;
	static bool isneighbor(string &a, string &b)
	{
		bool neighbor = false;
		string::iterator ia = a.begin();
		string::iterator ib = b.begin();
		for (; ia != a.end(); ++ia, ++ib)
		{
			if (ia[0] != ib[0])
			{
				if (neighbor) return false;
				else neighbor = true;
			}
		}
		return neighbor;
	}
	void revsearch(unordered_set<string> &dict)
	{
		vector<string> nextrow;
		vector<string> &row = layer.rbegin()[0];
		vector<string>::iterator word = row.begin();
		for (; word != row.end(); ++word)
		{
			if (isneighbor(target, word[0])) return;
			string::iterator letter = word[0].begin();
			for (char rc; letter != word[0].end(); ++letter)
			{
				rc = letter[0];
				for (char c = 'a'; c <= 'z'; ++c)
				{
					letter[0] = c;
					unordered_set<string>::iterator it;
					if ((it = dict.find(word[0])) != dict.end())
					{
						nextrow.push_back(word[0]);
						dict.erase(it);
					}
				}
				letter[0] = rc;
			}
		}
		if (nextrow.size() != 0)
		{
			// continue generating next row until near start
			layer.push_back(nextrow);
			revsearch(dict);
		}
	}
	void anspath(vector<string> &trace, int max)
	{
		if (max < 0) result.push_back(trace);
		else
		{
			vector<string> &row = layer[max];
			vector<string>::iterator word = row.begin();
			for (; word != row.end(); ++word)
			{
				if (isneighbor(trace.rbegin()[0], word[0]))
				{
					trace.push_back(word[0]);
					anspath(trace, max - 1);
					trace.pop_back();
				}
			}
		}
	}
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
	{
		vector<string> trace(1);
		// first breadth first search end to start path
		target = start;
		trace[0] = end;
		layer.push_back(trace);	// begin search point end
		revsearch(dict);
		// then depth first search start to end path
		trace[0] = start;	// begin search point start
		anspath(trace, layer.size() - 1);
		return result;
	}
};

/*
idea: reverse bfs(end->start) finds potential nodes, then dfs(start->end) finds path
complexity: Time O(N * length)
*/

int main(void)
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	Solution engine;
	cout << engine.findLadders("hit", "cog", dict).size() << '\n';
	return 0;
}
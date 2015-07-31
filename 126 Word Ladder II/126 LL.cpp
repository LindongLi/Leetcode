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
	void revsearch(unordered_set<string> &dict, string &target)
	{
		vector<string> nextrow;
		vector<string>::iterator word = layer.back().begin();
		for (; word != layer.back().end(); ++word)
		{
			if (isneighbor(word[0], target)) return;	// terminate neighboring target
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
			// continue generating next row
			layer.push_back(nextrow);
			revsearch(dict, target);
		}
	}
	void answerpath(vector<string> &trace, int max)
	{
		if (max < 0) result.push_back(trace);
		else
		{
			vector<string> &row = layer[max];
			vector<string>::iterator word = row.begin();
			for (; word != row.end(); ++word)
			{
				if (isneighbor(trace.back(), word[0]))
				{
					trace.push_back(word[0]);
					answerpath(trace, max - 1);
					trace.pop_back();
				}
			}
		}
	}
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
	{
		// first breadth first search string end to string start path
		// construct first breadth from string end
		layer.push_back(vector<string> (1, end));
		revsearch(dict, start);
		// then depth first search start to end path
		// construct first depth from string start
		vector<string> trace(1, start);
		answerpath(trace, layer.size() - 1);
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
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
https://leetcode.com/problems/word-ladder/

Given two words (beginWord and endWord), and a dictionary,
find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution
{
private:
	vector<vector<string> > layer;
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
	bool revsearch(unordered_set<string> &dict, string &target)
	{
		vector<string> nextrow;
		vector<string>::iterator word = layer.back().begin();
		for (; word != layer.back().end(); ++word)
		{
			if (isneighbor(word[0], target)) return true;	// found
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
			return revsearch(dict, target);
		}
		return false;
	}
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		if (beginWord == endWord) return 0;
		// breadth first search string end to string start path
		// construct first breadth from string end
		layer.push_back(vector<string>(1, endWord));
		if (!revsearch(wordDict, beginWord)) return 0;
		return layer.size() + 1;
	}
};

/*
idea: reverse bfs(end->start) finds potential nodes, answer is layer breadth
complexity: Time O(N * length)
*/

int main(void)
{
	unordered_set<string> wordDict;
	wordDict.insert("hot");
	wordDict.insert("dot");
	wordDict.insert("dog");
	wordDict.insert("lot");
	wordDict.insert("log");
	Solution engine;
	cout << engine.ladderLength("hit", "cog", wordDict) << '\n';
	return 0;
}
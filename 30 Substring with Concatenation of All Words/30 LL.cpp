#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word
in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<int> result;
		int nseq = words.size();
		if (nseq == 0) return result;
		int length = words[0].length();
		// map string to a count board
		vector<int> count_board;
		unordered_map<string, int> map;
		for (int i = 0; i < nseq; ++i)
		{
			unordered_map<string, int>::iterator it;
			if ((it = map.find(words[i])) != map.end())
			{
				++count_board[it->second];
			}
			else
			{
				map[words[i]] = count_board.size();
				count_board.push_back(1);
			}
		}
		// scan string count_board index
		vector<int> scan(s.size() - length + 1, -1);
		for (int i = 0; i < scan.size(); ++i)
		{
			unordered_map<string, int>::iterator it;
			if ((it = map.find(s.substr(i, length))) != map.end())
			{
				scan[i] = it->second;
			}
		}
		for(int i = 0; i < count_board.size(); ++i) cout << count_board[i] << endl;
		for(int i = 0; i < scan.size(); ++i) cout << scan[i] << endl;
		vector<int> trace;
		int targetlengh = nseq * length;
		for (int i = 0; i < length; ++i)
		{
			int todo = nseq;
			trace.assign(count_board.begin(), count_board.end());
			for (int head = i, tail = i; head < scan.size(); head += length)
			{
				if ((head - tail) == targetlengh)
				{
					if (++trace[scan[tail]] > 0)
					{
						++todo;
					}
					tail += length;
				}
				if (scan[head] < 0)
				{
					todo = nseq;
					tail = head + length;
					trace.assign(count_board.begin(), count_board.end());
				}
				else
				{
					if (--trace[scan[head]] >= 0)
					{
						if (--todo == 0)
						{
							result.push_back(tail);
						}
					}
				}
			}
			
		}
		return result;
	}
};

/*
idea: linear scan, boost by hash map
complexity: Time O(N)
*/

int main(void)
{
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("foo");
	Solution engine;
	cout << engine.findSubstring("abarfoofoo", words).size() << '\n';
	return 0;
}
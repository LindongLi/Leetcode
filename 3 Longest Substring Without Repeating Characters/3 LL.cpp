#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		// record previous position for every char
		vector<int> prePos(256, -1);
		int result = 0;	// best answer
		int current = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			// substring length extend
			current = min(current + 1, i - prePos[int(s[i])]);
			prePos[int(s[i])] = i;
			result = max(result, current);
		}
		return result;
	}
};

/*
idea: forward tracing string extend and limit
complexity: reverse O(N * result), forward O(N)
*/

int main(void)
{
	Solution engine;
	cout << engine.lengthOfLongestSubstring("bbbbb") << '\n';
	return 0;
}
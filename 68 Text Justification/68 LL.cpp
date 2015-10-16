#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/text-justification/

Given an array of words and a length L,
format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach;
that is, pack as many words as you can in each line.
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words,
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

class Solution
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		vector<string> result;
		int widthToUse = maxWidth;
		int slide = 0;	// input index
		for (int i = 0; i < words.size(); ++i)
		{
			if (widthToUse < int(words[i].length()))
			{
				string answer;
				widthToUse += (i - slide);
				for (; slide < (i - 1); ++slide)
				{
					answer += words[slide];
					// ensure left assign more spaces;
					int spaces = (widthToUse + i - slide - 2) / (i - slide - 1);
					widthToUse -= spaces;
					answer += string(spaces, ' ');
				}
				answer += words[slide++];
				answer += string(widthToUse, ' ');
				result.push_back(answer);
				widthToUse = maxWidth;
			}
			widthToUse -= words[i].length() + 1;	// at least one space
		}
		string answer;	// process last row
		for (; slide < (words.size() - 1); ++slide)
		{
			answer += words[slide];
			answer += ' ';
		}
		answer += words.back();
		answer += string(widthToUse + 1, ' ');
		result.push_back(answer);
		return result;
	}
};

/*
idea: greedy fulfill line by line
complexity: Time O(N)
*/

int main(void)
{
	vector<string> words;
	words.push_back("a");
	words.push_back("b");
	Solution engine;
	cout << engine.fullJustify(words, 10).size() << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;
struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/*
https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

class Solution
{
private:
	static bool compare(Interval &a, Interval &b)
	{
		return (a.start < b.start);
	}
public:
	vector<Interval> merge(vector<Interval>& intervals)
	{
		if (intervals.size() < 2) return intervals;
		sort(intervals.begin(), intervals.end(), Solution::compare);
		vector<Interval>::iterator read = intervals.begin() + 1;
		vector<Interval>::iterator write = intervals.begin();
		for (; read != intervals.end(); ++read)
		{
			if (write[0].end >= read[0].start)
			{
				write[0].end = max(write[0].end, read[0].end);
				continue;
			}
			++write;
			write[0].start = read[0].start;
			write[0].end = read[0].end;
		}
		intervals.erase(write + 1, intervals.end());
		return intervals;
	}
};

/*
idea: sort and loop merge, delete tail
complexity: Time O(NlogN)
*/

int main(void)
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 3));
	intervals.push_back(Interval(2, 6));
	Solution engine;
	cout << engine.merge(intervals).size() << '\n';
	return 0;
}
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
https://leetcode.com/problems/insert-interval/

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

class Solution
{
private:
	vector<Interval>::iterator data;
	int findhead(int val, int min, int max)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (val < data[mid].start)
			{
				max = mid - 1;
			}
			else if (val > data[mid].end)
			{
				min = mid + 1;
			}
			else return mid;
		}
		if (val > data[max].end) return max + 1;
		if (val > data[min].end) return min + 1;
		return min;
	}
	int findright(int val, int min, int max)
	{
		while ((min + 1) < max)
		{
			int mid = (min + max) >> 1;
			if (val < data[mid].start)
			{
				max = mid;
			}
			else
			{
				min = mid;
			}
		}
		if (val < data[min].start) return min - 1;
		if (val < data[max].start) return max - 1;
		return max;
	}
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		if (intervals.size() == 0)
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		int left, right;
		data = intervals.begin();
		if ((left = findleft(newInterval.start, 0, intervals.size() - 1)) == intervals.size())
		{
			intervals.push_back(newInterval);
		}
		else
		{
			if ((right = findright(newInterval.end, 0, intervals.size() - 1)) < 0)
			{
				intervals.insert(intervals.begin(), newInterval);
			}
			else
			{
				intervals[right].start = min(intervals[left].start, newInterval.start);
				intervals[right].end = max(intervals[right].end, newInterval.end);
				if (left != right)
				{
					intervals.erase(intervals.begin() + left, intervals.begin() + right);
				}
			}
		}
		return intervals;
	}
};


/*
idea: binary search start & end position, merge and erase middle
complexity: Time O(N)
*/

int main(void)
{
	vector<Interval> intervals;
	intervals.push_back(*new Interval(3, 5));
	intervals.push_back(*new Interval(12, 15));
	Solution engine;
	cout << engine.insert(intervals, *new Interval(6, 6)).size() << '\n';
	return 0;
}
#include <vector>
#include <iostream>
using namespace std;
struct Interval {
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
	vector<Interval> *pintervals;
	int findtime(int time, int l, int r)
	{
		if(r <= (l + 1))
		{
			if(time < (*pintervals)[l].start) return l - 1;
			
		}
	}
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        
    }
};
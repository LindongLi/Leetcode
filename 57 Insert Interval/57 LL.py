class Interval(object):
	def __init__(self, s=0, e=0):
		self.start = s
		self.end = e

class Solution(object):
	@staticmethod
	def findStart(intervals, startval):
		min = 0
		max = len(intervals) - 1
		while (max - min) > 1:
			mid = min + ((max - min) >> 1)
			if intervals[mid].end < startval:
				min = mid + 1
			else:
				max = mid
		if intervals[min].end >= startval:
			return min
		if intervals[max].end >= startval:
			return max
		return max + 1
	@staticmethod
	def findEnd(intervals, endval):
		min = 0
		max = len(intervals) - 1
		while (max - min) > 1:
			mid = min + ((max - min) >> 1)
			if endval < intervals[mid].start:
				max = mid - 1
			else:
				min = mid
		if intervals[max].start <= endval:
			return max
		if intervals[min].start <= endval:
			return min
		return min - 1
	def insert(self, intervals, newInterval):
		if len(intervals) == 0:
			return [newInterval]
		StartPos = Solution.findStart(intervals, newInterval.start)
		EndPos = Solution.findEnd(intervals, newInterval.end)
		print StartPos, EndPos
		if StartPos == len(intervals):
			intervals.append(newInterval)
		elif EndPos == -1 or StartPos > EndPos:
			intervals.insert(StartPos, newInterval)
		else:
			intervals[StartPos].start = min(intervals[StartPos].start, newInterval.start)
			intervals[StartPos].end = max(intervals[EndPos].end, newInterval.end)
			if StartPos != EndPos:
				return list(intervals[:StartPos + 1] + intervals[EndPos + 1:])
		return intervals

engine = Solution()
print engine.insert([Interval(1,5)], Interval(2,3))
class Solution(object):
	def merge(self, intervals):
		result = list()
		for i in sorted(intervals, key = lambda x: x.start):
			if len(result) != 0 and i.start <= result[-1].end:
				result[-1].end = max(result[-1].end, i.end)
			else:
				result.append(i)
		return result

engine = Solution()
print engine.merge(None)
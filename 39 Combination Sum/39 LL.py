class Solution(object):
	@staticmethod
	def search(result, trace, candidates, target):
		if target == 0:
			result.append(list(trace))
			return
		for i in xrange(len(candidates)):
			if candidates[i] > target:
				return
			trace.append(candidates[i])
			Solution.search(result, trace, candidates[i:], target - candidates[i])
			trace.pop()
	def combinationSum(self, candidates, target):
		result = list()
		Solution.search(result, [], sorted(candidates), target)
		return result

engine = Solution()
print engine.combinationSum([2, 3, 6, 7], 7)
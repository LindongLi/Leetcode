class Solution(object):
	@staticmethod
	def search(result, trace, candidates, target):
		if target == 0:
			result.append(list(trace))
			return
		for i in xrange(len(candidates)):
			if i != 0 and candidates[i - 1] == candidates[i]:
				continue
			if candidates[i] > target:
				return
			trace.append(candidates[i])
			Solution.search(result, trace, candidates[(i + 1):], target - candidates[i])
			trace.pop()
	def combinationSum2(self, candidates, target):
		result = list()
		Solution.search(result, [], sorted(candidates), target)
		return result

engine = Solution()
print engine.combinationSum2([1, 2, 1, 1], 3)
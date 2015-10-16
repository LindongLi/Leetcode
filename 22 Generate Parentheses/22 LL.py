class Solution(object):
	@staticmethod
	def search(trace, left, right, result):
		if left > 0:
			trace.append('(')
			Solution.search(trace, left - 1, right, result)
			trace.pop()
		if left < right:
			trace.append(')')
			Solution.search(trace, left, right - 1, result)
			trace.pop()
		if right == 0:
			result.append(''.join(trace))
	def generateParenthesis(self, n):
		result = list()
		Solution.search([], n, n, result)
		return result

engine = Solution()
print engine.generateParenthesis(0)
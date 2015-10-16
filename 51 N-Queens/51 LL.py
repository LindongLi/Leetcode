class Solution(object):
	@staticmethod
	def search(cur, n, trace, result):
		if cur == n:
			answer = []
			for i in xrange(n):
				answer.append('.' * trace[i] + 'Q' + '.' * (n - trace[i] - 1))
			result.append(answer)
		for i in xrange(n):
			isResult = True
			for j in xrange(len(trace)):
				if i == trace[j] or abs(i - trace[j]) == (len(trace) - j):
					isResult = False
					break
			if isResult:
				trace.append(i)
				Solution.search(cur + 1, n, trace, result)
				trace.pop()
	def solveNQueens(self, n):
		result = list()
		Solution.search(0, n, [], result)
		return result

engine = Solution()
print engine.solveNQueens(4)
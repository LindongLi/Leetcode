class Solution(object):
	@staticmethod
	def search(cur, n, vert, ldiag, rdiag):
		if cur == n:
			return 1
		result = 0
		for i in xrange(n):
			if vert[i] or ldiag[cur + i] or rdiag[cur + n - 1 - i]:
				continue
			vert[i] = True
			ldiag[cur + i] = True
			rdiag[cur + n - 1 - i] = True
			result += Solution.search(cur + 1, n, vert, ldiag, rdiag)
			vert[i] = False
			ldiag[cur + i] = False
			rdiag[cur + n - 1 - i] = False
		return result
	def totalNQueens(self, n):
		ndiag = n + n - 1
		return Solution.search(0, n, [False] * n, [False] * ndiag, [False] * ndiag)

engine = Solution()
print engine.totalNQueens(4)
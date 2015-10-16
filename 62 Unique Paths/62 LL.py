class Solution(object):
	def uniquePaths(self, m, n):
		m -= 1
		n -= 1
		total = m + n
		select = min(m, n)
		result = 1 if select >= 0 else 0
		for i in xrange(select):
			result = result * (total - i) / (i + 1)
		return result

engine = Solution()
print engine.uniquePaths(2, 2)
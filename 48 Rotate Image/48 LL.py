class Solution(object):
	def rotate(self, matrix):
		n = len(matrix)
		for i in range((n + 1) >> 1):
			for j in range(n >> 1):
				cache = matrix[i][j]
				matrix[i][j] = matrix[n - 1 - j][i]
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
				matrix[j][n - 1 - i] = cache

engine = Solution()
engine.rotate([[1, 2], [3, 4]])
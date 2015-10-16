class Solution(object):
	def minPathSum(self, grid):
		height = len(grid)
		if height == 0:
			return 0
		width = len(grid[0])
		if width == 0:
			return 0
		smap = [0] * width
		smap[0] = grid[0][0]
		for i in xrange(1, width):
			smap[i] = smap[i - 1] + grid[0][i]
		for j in xrange(1, height):
			smap[0] += grid[j][0]
			for i in xrange(1, width):
				smap[i] = min(smap[i - 1], smap[i]) + grid[j][i]
		return smap[-1]

engine = Solution()
print engine.minPathSum([[1, 3], [4, 1]])
class Solution(object):
	def uniquePathsWithObstacles(self, obstacleGrid):
		height = len(obstacleGrid)
		if height == 0:
			return 0
		width = len(obstacleGrid[0])
		if width == 0 or obstacleGrid[0][0] == 1:
			return 0
		smap = [1] * width
		for i in xrange(1, width):
			smap[i] = min(smap[i - 1] , 1 - obstacleGrid[0][i])
		for j in xrange(1, height):
			if obstacleGrid[j][0] == 1:
				smap[0] = 0
			for i in xrange(1, width):
				if obstacleGrid[j][i] == 1:
					smap[i] = 0
				else:
					smap[i] += smap[i - 1]
		return smap[-1]

engine = Solution()
print engine.uniquePathsWithObstacles([[0, 0], [0, 0]])
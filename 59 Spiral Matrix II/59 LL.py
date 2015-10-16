class Solution(object):
	def generateMatrix(self, n):
		if n == 0:
			return []
		result = [[0] * n for i in xrange(n)]
		xpos = -1
		ypos = 0
		count = 0
		while True:
			for i in xrange(n):
				xpos += 1
				count += 1
				result[ypos][xpos] = count
			n -= 1
			if n == 0:
				break
			for i in xrange(n):
				ypos += 1
				count += 1
				result[ypos][xpos] = count
			for i in xrange(n):
				xpos -= 1
				count += 1
				result[ypos][xpos] = count
			n -= 1
			if n == 0:
				break
			for i in xrange(n):
				ypos -= 1
				count += 1
				result[ypos][xpos] = count
		return result

engine = Solution()
print engine.generateMatrix(3)
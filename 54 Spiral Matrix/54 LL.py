class Solution(object):
	def spiralOrder(self, matrix):
		result = list()
		position = [0, -1]
		yheight = len(matrix) - 1
		xwidth = (0 if yheight < 0 else len(matrix[0]))
		step = 1
		while True:
			if xwidth == 0:
				break
			for i in xrange(xwidth):
				position[1] += step
				result.append(matrix[position[0]][position[1]])
			xwidth -= 1
			if yheight == 0:
				break
			for i in xrange(yheight):
				position[0] += step
				result.append(matrix[position[0]][position[1]])
			yheight -= 1
			step = -step
		return result

engine = Solution()
print engine.spiralOrder([[1, 2, 3] for x in xrange(3)])
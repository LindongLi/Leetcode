class Solution(object):
	def trap(self, height):
		maxval = 0
		maxlpos = 0
		maxrpos = 0
		for i in xrange(len(height)):
			if maxval < height[i]:
				maxval = height[i]
				maxlpos = i
				maxrpos = i
			elif maxval == height[i]:
				maxrpos = i
		result = 0
		bar = 0
		for i in xrange(maxlpos):
			bar = max(bar, height[i])
			result += bar - height[i]
		for i in xrange(maxlpos + 1, maxrpos):
			result += maxval - height[i]
		bar = 0
		for i in xrange(len(height) - 1, maxrpos, -1):
			bar = max(bar, height[i])
			result += bar - height[i]
		return result

engine = Solution()
print engine.trap([0, 1, 0, 2, 1, 0, 1, 3, 2,1, 2, 1])
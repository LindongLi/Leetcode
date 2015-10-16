class Solution(object):
	def maxArea(self, height):
		area = 0
		left = 0
		right = len(height) - 1
		while left < right:
			area = max(area, (right - left) * min(height[left], height[right]))
			if height[left] <= height[right]:
				left += 1
			else:
				right -= 1
		return area

engine = Solution()
print engine.maxArea([1, 2, 3])
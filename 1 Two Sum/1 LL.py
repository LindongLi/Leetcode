class Solution(object):
	def twoSum(self, nums, target):
		map = dict()
		for i, value in enumerate(nums):
			if map.has_key(value):
				return [map[value] + 1, i + 1]
			else:
				map[target - value] = i
		return [-1, -1]

engine = Solution()
print engine.twoSum([1, 2, 3], 3)
class Solution(object):
	@staticmethod
	def findgap(nums, min, max):
		while (min + 1) < max:
			mid = min + ((max - min) >> 1)
			if nums[min] < nums[mid]:
				min = mid
			else:
				max = mid
		return min
	@staticmethod
	def binary(nums, min, max, target):
		while (min + 1) < max:
			mid = min + ((max - min) >> 1)
			if nums[mid] < target:
				min = mid + 1
			else:
				max = mid
		if nums[min] == target:
			return min
		if nums[max] == target:
			return max
		return -1
	def search(self, nums, target):
		if len(nums) == 0:
			return -1
		min = 0
		max = len(nums) - 1
		if min == max or nums[min] < nums[max]:
			return Solution.binary(nums, min, max, target)
		gap = Solution.findgap(nums, min, max)
		if nums[min] <= target:
			return Solution.binary(nums, min, gap, target)
		return Solution.binary(nums, gap + 1, max, target)

engine = Solution()
print engine.search([1, 2, 3, 4], 1)
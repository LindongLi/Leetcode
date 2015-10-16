class Solution(object):
	@staticmethod
	def leftsearch(nums, min, max, target):
		while min < (max - 1):
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
	@staticmethod
	def rightsearch(nums, min, max, target):
		while min < (max - 1):
			mid = min + ((max - min) >> 1)
			if nums[mid] <= target:
				min = mid
			else:
				max = mid - 1
		if nums[max] == target:
			return max
		if nums[min] == target:
			return min
		return -1
	def searchRange(self, nums, target):
		if len(nums) == 0:
			return [-1, -1]
		min = 0
		max = len(nums) - 1
		return [Solution.leftsearch(nums, min, max, target), Solution.rightsearch(nums, min, max, target)]

engine = Solution()
print engine.searchRange([1, 2, 2, 2], 2)
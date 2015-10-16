class Solution(object):
	def searchInsert(self, nums, target):
		min = 0
		max = len(nums) - 1
		while min < (max - 1):
			mid = min + ((max - min) >> 1)
			if nums[mid] < target:
				min = mid + 1
			else:
				max = mid
		if nums[min] >= target:
			return min
		if nums[max] >= target:
			return max
		return max + 1

engine =Solution()
print engine.searchInsert([1, 3], 2)
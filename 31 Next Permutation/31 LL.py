class Solution(object):
	def nextPermutation(self, nums):
		i = len(nums) - 2
		while i >= 0:
			if nums[i] < nums[i + 1]:
				break
			i -= 1
		if i < 0:
			nums.reverse()
			return
		spos = i + 1
		for j in range(i + 2, len(nums)):
			if nums[j] > nums[i] and nums[j] < nums[spos]:
				spos = j
		cache = nums[i]
		nums[i] = nums[spos]
		nums[spos] = cache
		nums[i + 1:] = sorted(nums[i + 1:])

engine = Solution()
engine.nextPermutation([3, 3, 2])
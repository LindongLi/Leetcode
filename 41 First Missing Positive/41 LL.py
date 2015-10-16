class Solution(object):
	def firstMissingPositive(self, nums):
		for i in xrange(len(nums)):
			pos = nums[i] - 1
			while pos != i and pos >= 0 and pos < len(nums) and nums[i] != nums[pos]:
				nums[i], nums[pos] = nums[pos], nums[i]
				pos = nums[i] - 1
		for i in xrange(len(nums)):
			if nums[i] != (i + 1):
				return (i + 1)
		return len(nums) + 1

engine = Solution()
print engine.firstMissingPositive([2, 1])
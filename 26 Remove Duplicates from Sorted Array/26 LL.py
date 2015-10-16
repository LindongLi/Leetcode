class Solution(object):
	def removeDuplicates(self, nums):
		write = 1
		if len(nums) == 0:
			return 0
		for read in range(1, len(nums)):
			if nums[read - 1] != nums[read]:
				nums[write] = nums[read]
				write += 1
		return write

engine = Solution()
print engine.removeDuplicates([1, 1, 2])
class Solution(object):
	def removeElement(self, nums, val):
		write = 0
		for read in range(len(nums)):
			if nums[read] != val:
				nums[write] = nums[read]
				write += 1
		return write

engine = Solution()
print engine.removeElement([1, 2], 1)
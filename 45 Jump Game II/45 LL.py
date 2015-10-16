class Solution(object):
	def jump(self, nums):
		steps = [len(nums)] * len(nums)
		steps[0] = 0
		for i in xrange(len(nums) - 1):
			for j in xrange(min(i + nums[i], len(nums) - 1), i, -1):
				if steps[j] > (steps[i] + 1):
					steps[j] = steps[i] + 1
				else:
					break
		return steps[-1]

engine = Solution()
print engine.jump([2, 3, 1, 1, 4])
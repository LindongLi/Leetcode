class Solution(object):
	@staticmethod
	def search(nums, n, result):
		if len(nums) == n:
			result.append(list(nums))
			return
		Solution.search(nums, n + 1, result)
		valuelist = [nums[n]]
		for i in xrange(n + 1, len(nums)):
			if nums[i] in valuelist:
				continue
			valuelist.append(nums[i])
			nums[n], nums[i] = nums[i], nums[n]
			Solution.search(nums, n + 1, result)
			nums[n], nums[i] = nums[i], nums[n]
	def permuteUnique(self, nums):
		result = list()
		Solution.search(nums, 0, result)
		return result

engine = Solution()
print engine.permuteUnique([2, 3, 2])
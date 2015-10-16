class Solution(object):
	@staticmethod
	def search(nums, left, right):
		if left == right:
			return (nums[left], nums[left], nums[left], nums[left])
		mid = left + ((right - left) >> 1)
		result1, sum1, lsum1, rsum1 = Solution.search(nums, left, mid)
		result2, sum2, lsum2, rsum2 = Solution.search(nums, mid + 1, right)
		result = max(result1, result2, rsum1 + lsum2)
		lsum = max(lsum1, sum1 + lsum2)
		rsum = max(rsum2, rsum1 + sum2)
		return (result, sum1 + sum2, lsum, rsum)
	def maxSubArray(self, nums):
		return Solution.search(nums, 0, len(nums) - 1)[0]

engine = Solution()
print engine.maxSubArray([-1, 1, 3])
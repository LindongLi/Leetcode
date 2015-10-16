class Solution(object):
	def threeSum(self, nums):
		result = list()
		if(len(nums) < 3):
			return result
		nums.sort()
		val_a = ~nums[0]
		for a in range(0, len(nums)):
			if val_a == nums[a]:
				continue
			val_a = nums[a]
			b = a + 1
			c = len(nums) - 1
			while b < c:
				if val_a + nums[b] + nums[c] < 0:
					b += 1
				elif val_a + nums[b] + nums[c] == 0:
					result.append([val_a, nums[b], nums[c]])
					val_b = nums[b]
					while b < c and val_b == nums[b]:
						b += 1
				else:
					c -= 1
		return result

engine = Solution()
print engine.threeSum([2, 0, -2])
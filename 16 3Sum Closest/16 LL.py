class Solution(object):
	def threeSumClosest(self, nums, target):
		if(len(nums) < 3):
			return 0
		nums.sort()
		result = nums[0] + nums[1] + nums[2]
		val_a = ~nums[0]
		for a in range(0, len(nums)):
			if val_a == nums[a]:
				continue
			val_a = nums[a]
			b = a + 1
			c = len(nums) - 1
			while b < c:
				attempt = val_a + nums[b] + nums[c]
				if abs(target - attempt) < abs(target - result):
					result = attempt
				if attempt < target:
					b += 1
				elif attempt == target:
					return target
				else:
					c -= 1
		return result

engine = Solution()
print engine.threeSumClosest([-1, 2, 1, -4], 1)
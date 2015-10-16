class Solution(object):
	def canJump(self, nums):
		position = 0
		reachable = 0
		while position <= reachable:
			reachable = max(reachable, position + nums[position])
			if reachable >= len(nums) - 1:
				return True
			position += 1
		return False

engine = Solution()
print engine.canJump([1,1])
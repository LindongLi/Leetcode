class Solution(object):
	@staticmethod
	def validNum(string, maxpart):
		if string != str() and (string[0] == '+' or string[0] == '-'):
			string = string[1:]
		nums = string.split('.')
		emptycnt = len(nums)
		if len(nums) > maxpart:
			return False
		if nums[0] == str():
			emptycnt -= 1
		for i in xrange(len(nums[0])):
			if nums[0][i] < '0' or nums[0][i] > '9':
				return False
		if len(nums) == 2:
			if nums[1] == str():
				emptycnt -= 1
			for i in xrange(len(nums[1])):
				if nums[1][i] < '0' or nums[1][i] > '9':
					return False
		return emptycnt != 0
	def isNumber(self, s):
		part = s.strip().split('e')
		if len(part) > 2:
			return False
		result = Solution.validNum(part[0], 2)
		if len(part) == 2 and result:
			result = Solution.validNum(part[1], 1)
		return result

engine = Solution()
print engine.isNumber(" +0.e0  ")
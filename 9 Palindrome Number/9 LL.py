class Solution(object):
	def isPalindrome(self, x):
		if x < 0:
			return False
		mask = 1
		while (x / 10) >= mask:
			mask *= 10
		while mask > 1:
			if ((x - x / mask) % 10) != 0:
				return False
			x /= 10
			mask /= 100
		return True

engine = Solution()
print engine.isPalindrome(12)
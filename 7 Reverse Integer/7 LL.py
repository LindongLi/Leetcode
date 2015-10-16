class Solution(object):
	def reverse(self, x):
		if x == ~0x7FFFFFFF:
			return 0
		neg = (x < 0)
		x = -x if neg else x
		digits = list()
		while x > 0:
			digits.append(x % 10)
			x /= 10
		result = 0
		for i in range(0, len(digits)):
			result = result * 10 + digits[i]
		result = 0 if result > 0x7FFFFFFF else result
		return -result if neg else result

engine = Solution()
print engine.reverse(-123)
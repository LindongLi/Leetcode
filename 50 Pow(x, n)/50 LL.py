class Solution(object):
	def myPow(self, x, n):
		neg = (n < 0)
		if neg:
			n = -n
		result = 1
		while n != 0:
			if n & 0x1:
				result *= x
			x *= x
			n >>= 1
		return (1.0 / result) if neg else result

engine = Solution()
print engine.myPow(1.1, -3)
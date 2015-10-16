class Solution(object):
	def divide(self, dividend, divisor):
		neg = (dividend < 0) ^ (divisor < 0)
		dividend = abs(dividend)
		divisor = abs(divisor)
		lshift = 0
		mask = divisor
		mask |= mask >> 1
		mask |= mask >> 2
		mask |= mask >> 4
		mask |= mask >> 8
		mask |= mask >> 16
		while dividend > mask:
			lshift += 1
			divisor <<= 1
			mask = (mask << 1) | 1
		mask = 0
		while lshift >= 0:
			if dividend >= divisor:
				dividend -= divisor
				mask |= (1 << lshift)
			divisor >>= 1
			lshift -= 1
		if not neg and mask > 0x7FFFFFFF:
			return 0x7FFFFFFF
		return -mask if neg else mask
class Solution(object):
	def plusOne(self, digits):
		digits = digits[::-1]
		carry = 1
		for i in xrange(len(digits)):
			carry += digits[i]
			if carry >= 10:
				digits[i] = carry - 10
				carry = 1
			else:
				digits[i] = carry
				carry = 0
		if carry:
			digits.append(carry)
		return digits[::-1]

engine = Solution()
print engine.plusOne([1, 2, 9])
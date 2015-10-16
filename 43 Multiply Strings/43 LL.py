class Solution(object):
	def multiply(self, num1, num2):
		num1 = [ord(x) - ord('0') for x in reversed(num1)]
		num2 = [ord(x) - ord('0') for x in reversed(num2)]
		if len(num1) == 0 or (len(num1) == 1 and num1[0] == 0):
			return str('0')
		if len(num2) == 0 or (len(num2) == 1 and num2[0] == 0):
			return str('0')
		result = [0] * (len(num1) + len(num2))
		for i in xrange(len(num1)):
			for j in xrange(len(num2)):
				result[i + j] += num1[i] * num2[j]
		pos = 0
		carry = 0
		while pos < len(result):
			carry += result[pos]
			result[pos] = chr(carry % 10 + ord('0'))
			carry /= 10
			pos += 1
		while carry != 0:
			result.append(chr(carry % 10 + ord('0')))
			carry /= 10
		while result[-1] == '0':
			result.pop()
		return ''.join(reversed(result))

engine = Solution()
print engine.multiply("12", "9999999999")
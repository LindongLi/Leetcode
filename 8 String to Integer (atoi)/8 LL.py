class Solution(object):
	def myAtoi(self, str):
		pos = 0
		while pos != len(str) and str[pos] == ' ':
			pos += 1
		neg = False
		if pos != len(str) and (str[pos] == '+' or str[pos] == '-'):
			neg = (str[pos] == '-')
			pos += 1
		result = 0
		while pos != len(str):
			if not str[pos].isdigit():
				break
			result = result * 10 + ord(str[pos]) - ord('0')
			if result > 0x7FFFFFFF:
				return ~0x7FFFFFFF if neg else 0x7FFFFFFF
			pos += 1
		return -result if neg else result

engine = Solution()
print engine.myAtoi(" -12345678901")
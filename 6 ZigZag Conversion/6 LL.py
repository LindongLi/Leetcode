class Solution(object):
	def convert(self, s, numRows):
		if numRows < 2:
			return s
		result = str()
		row = numRows + numRows - 2
		for i in range(0, len(s), row):
			result += s[i]
		for i in range(1, numRows - 1):
			for j in range(0, len(s) - i, row):
				result += s[i + j]
				if (row - i + j) >= len(s):
					break
				result += s[row - i + j]
		for i in range(numRows - 1, len(s), row):
			result += s[i]
		return result

engine = Solution()
print engine.convert("123456789A", 3)
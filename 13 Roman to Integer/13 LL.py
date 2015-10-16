class Solution(object):
	def romanToInt(self, s):
		map = {'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}
		result = 0
		curval = 0
		for c in s:
			nextval = map[c]
			if curval < nextval:
				result -= curval
			else:
				result += curval
			curval = nextval
		result += curval
		return result

engine = Solution()
print engine.romanToInt("XXXIX")
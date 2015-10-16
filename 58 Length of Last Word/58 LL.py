class Solution(object):
	def lengthOfLastWord(self, s):
		result = 0
		for c in s.rstrip()[::-1]:
			if c == ' ':
				break
			result += 1
		return result

engine = Solution()
print engine.lengthOfLastWord("123 456 ")
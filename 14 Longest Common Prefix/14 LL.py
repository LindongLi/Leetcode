class Solution(object):
	def longestCommonPrefix(self, strs):
		prefix = str()
		if len(strs) == 0:
			return prefix
		commonlen = 0
		while commonlen != len(strs[0]):
			c = strs[0][commonlen]
			for i in range(1, len(strs)):
				if commonlen == len(strs[i]) or strs[i][commonlen] != c:
					return prefix
			prefix += c
			commonlen += 1
		return prefix

engine = Solution()
print engine.longestCommonPrefix(["123", "12", "12"])
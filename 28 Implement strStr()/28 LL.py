class Solution(object):
	def strStr(self, haystack, needle):
		scaned = 0
		while True:
			i = 0
			while True:
				if i >= len(needle):
					return scaned
				if scaned + i >= len(haystack):
					return -1
				if haystack[scaned + i] != needle[i]:
					break
				i += 1
			scaned += 1
		return -1

engine = Solution()
print engine.strStr("abcd", "cd")
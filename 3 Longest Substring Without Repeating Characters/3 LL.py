class Solution(object):
	def lengthOfLongestSubstring(self, s):
		result = 0
		answer = 0
		map = [-1] * 256
		for i in range(0, len(s)):
			answer = min(answer + 1, i - map[ord(s[i])])
			map[ord(s[i])] = i
			result = max(result, answer)
		return result

engine = Solution()
print engine.lengthOfLongestSubstring("abcdabc")
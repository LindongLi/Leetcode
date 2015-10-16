class Solution(object):
	def groupAnagrams(self, strs):
		answer = dict()
		for s in strs:
			skey = ''.join(sorted(s))
			if answer.has_key(skey):
				answer[skey].append(s)
			else:
				answer[skey] = [s]
		return [sorted(x) for x in answer.values()]

engine = Solution()
print engine.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
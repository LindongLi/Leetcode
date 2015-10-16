class Solution(object):
	def letterCombinations(self, digits):
		map = {'2':"abc", '3':"def", '4':"ghi",'5':"jkl", '6':"mno", '7':"pqrs", '8':"tuv", '9':"wxyz"}
		result = [""]
		for c in digits:
			if c < '2' or c > '9':
				continue
			cache = []
			for item in result:
				for bit in map[c]:
					cache.append(item + bit)
			result = cache
		return [] if len(result) == 1 else result

engine = Solution()
print engine.letterCombinations("23")
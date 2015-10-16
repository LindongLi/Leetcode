class Solution(object):
	def getPermutation(self, n, k):
		k -= 1
		mask = list()
		result = str()
		bits = [chr(ord('1') + i) for i in xrange(n)]
		if n >= 2:
			mask.append(1)
		for i in xrange(2, n):
			mask.append(mask[-1] * i)
		for i in xrange(len(mask)):
			index = k / mask[-1]
			k %= mask[-1]
			result += bits[index]
			del bits[index]
			mask.pop()
		result += bits[0]
		return result

engine = Solution()
print engine.getPermutation(1, 1)
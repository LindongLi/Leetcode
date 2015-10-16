class Solution(object):
	@staticmethod
	def loop(sayn):
		result = list()
		last = sayn[0]
		count = 1
		for i in xrange(1, len(sayn)):
			if last == sayn[i]:
				count += 1
			else:
				result.append(count)
				result.append(last)
				last = sayn[i]
				count = 1
		result.append(count)
		result.append(last)
		return result
	def countAndSay(self, n):
		result = [1]
		for i in xrange(1, n):
			result = Solution.loop(result)
		result = [str(x) for x in result]
		return ''.join(result)

engine = Solution()
print engine.countAndSay(20)
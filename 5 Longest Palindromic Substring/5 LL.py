class Solution(object):
	def longestPalindrome(self, s):
		table = [' ']
		for c in s:
			table.append(c)
			table.append(' ')
		position = 0
		center = 0
		right = 0
		P = [0] * len(table)
		for i in range(1, len(P)):
			if i <= right:
				P[i] = min(P[center - i + center], right - i)
			while i >= (P[i] + 1) and (i + P[i] + 1) < len(P) and table[i - P[i] - 1] == table[i + P[i] + 1]:
				P[i] += 1
			if (i + P[i]) > right:
				center = i
				right = i + P[i]
			if P[position] < P[i]:
				position = i
		return s[(position - P[position]) >> 1:(position + P[position]) >> 1]

engine = Solution()
print engine.longestPalindrome("banana")
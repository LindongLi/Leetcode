class Solution(object):
	def addBinary(self, a, b):
		va = [1 if a[i] == '1' else 0 for i in xrange(len(a)-1,-1,-1)]
		vb = [1 if b[i] == '1' else 0 for i in xrange(len(b)-1,-1,-1)]
		pos = 0
		carry = 0
		result = list()
		while True:
			loop = False
			if pos < len(va):
				carry += va[pos]
				loop = True
			if pos < len(vb):
				carry += vb[pos]
				loop = True
			if (not loop) and carry == 0:
				break
			result.append(chr(ord('0') + (carry & 1)))
			carry >>= 1
			pos += 1
		return ''.join(result[::-1])

engine = Solution()
print engine.addBinary("011111", "1")
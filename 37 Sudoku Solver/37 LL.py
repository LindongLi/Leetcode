class Solution(object):
	@staticmethod
	def check(board, r, c):
		record1 = [False] * 9
		record2 = [False] * 9
		for i in xrange(9):
			bit = ord(board[r][i])
			if ord('1') <= bit and bit <= ord('9'):
				if record1[bit - ord('1')]:
					return []
				record1[bit - ord('1')] = True
			bit = ord(board[i][c])
			if ord('1') <= bit and bit <= ord('9'):
				if record2[bit - ord('1')]:
					return []
				record2[bit - ord('1')] = True
		rbase = r - (r % 3)
		cbase = c - (c % 3)
		record = [False] * 9
		for r in xrange(rbase, rbase + 3):
			for c in xrange(cbase, cbase + 3):
				bit = ord(board[r][c])
				if ord('1') <= bit and bit <= ord('9'):
					if record[bit - ord('1')]:
						return []
					record[bit - ord('1')] = True
		return [x for x in xrange(9) if not (record[x] or record1[x] or record2[x])]
	@staticmethod
	def search(board, r, c):
		if r == 9:
			return True
		nextr, nextc = r, c + 1
		if nextc == 9:
			nextr += 1
			nextc = 0
		bit = ord(board[r][c])
		if ord('1') <= bit and bit <= ord('9'):
			return Solution.search(board, nextr, nextc)
		for n in Solution.check(board, r, c):
			board[r][c] = chr(ord('1') + n)
			if Solution.search(board, nextr, nextc):
				return True
		board[r][c] = '*'
		return False
	def solveSudoku(self, board):
		Solution.search(board, 0, 0)

engine = Solution()
engine.solveSudoku([['*' for c in xrange(9)] for r in xrange(9)])
class Solution(object):
	def isValidSudoku(self, board):
		for r in xrange(9):
			record1 = [False] * 9
			record2 = [False] * 9
			for c in xrange(9):
				bit = ord(board[r][c])
				if ord('1') <= bit and bit <= ord('9'):
					if record1[bit - ord('1')]:
						return False
					record1[bit - ord('1')] = True
				bit = ord(board[c][r])
				if ord('1') <= bit and bit <= ord('9'):
					if record2[bit - ord('1')]:
						return False
					record2[bit - ord('1')] = True
		for rbase in xrange(0, 9, 3):
			for cbase in xrange(0, 9, 3):
				record = [False] * 9
				for r in xrange(rbase, rbase + 3):
					for c in xrange(cbase, cbase + 3):
						bit = ord(board[r][c])
						if ord('1') <= bit and bit <= ord('9'):
							if record[bit - ord('1')]:
								return False
							record[bit - ord('1')] = True
		return True

engine = Solution()
print engine.isValidSudoku([['*' for c in xrange(9)] for r in xrange(9)])
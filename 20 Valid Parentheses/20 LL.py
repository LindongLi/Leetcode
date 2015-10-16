class Solution(object):
	def isValid(self, s):
		stack = ['*']
		for c in s:
			if c == '{' or c == '[' or c == '(':
				stack.append(c)
			elif c == '}':
				if stack[-1] != '{':
					return False
				stack.pop()
			elif c == ']':
				if stack[-1] != '[':
					return False
				stack.pop()
			elif c == ')':
				if stack[-1] != '(':
					return False
				stack.pop()
			else:
				return False
		return len(stack) == 1

engine = Solution()
print engine.isValid("([)]")
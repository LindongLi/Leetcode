class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		slide = ListNode(0)
		result = slide
		carry = 0
		while l1 or l2 or carry:
			if l1:
				carry += l1.val
				l1 = l1.next
			if l2:
				carry += l2.val
				l2 = l2.next
			if carry >= 10:
				slide.next = ListNode(carry - 10)
				carry = 1
			else:
				slide.next = ListNode(carry)
				carry = 0
			slide = slide.next
		return result.next if result.next else result

engine = Solution()
engine.addTwoNumbers(None, None)
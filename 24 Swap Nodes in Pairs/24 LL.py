class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def swapPairs(self, head):
		result = ListNode(0)
		result.next = head
		past = result
		while True:
			first = past.next
			if first is None:
				break
			second = first.next
			if second is None:
				break
			past.next = second
			first.next = second.next
			second.next = first
			past = first
		return result.next

engine = Solution()
print engine.swapPairs(None)
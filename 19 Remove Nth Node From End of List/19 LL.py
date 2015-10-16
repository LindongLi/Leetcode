class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def removeNthFromEnd(self, head, n):
		if head == None:
			return None
		result = ListNode(0)
		result.next = head
		remember = [None] * (n + 1)
		mempos = 0
		slide = result
		while slide != None:
			remember[mempos] = slide
			mempos += 1
			if mempos > n:
				mempos = 0
			slide = slide.next
		remember[mempos].next = remember[mempos].next.next
		return result.next

engine = Solution()
print engine.removeNthFromEnd(None, 0)
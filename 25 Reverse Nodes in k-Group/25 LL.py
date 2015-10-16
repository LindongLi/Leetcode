class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def reverseKGroup(self, head, k):
		result = ListNode(0)
		result.next = head
		slide = result
		while slide.next:
			lasttail = slide
			head = slide.next
			for i in range(k):
				slide = slide.next
				if slide is None:
					return result.next
			lasttail.next = slide
			lasttail = head
			linkpre = slide.next
			while linkpre != slide:
				cache = head.next
				head.next = linkpre
				linkpre = head
				head = cache
			slide = lasttail
		return result.next

engine = Solution()
print engine.reverseKGroup(None, 1)
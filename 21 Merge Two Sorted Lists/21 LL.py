class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def mergeTwoLists(self, l1, l2):
		result = ListNode(0)
		slide = result
		while l1 != None and l2 != None:
			if l1.val <= l2.val:
				slide.next = l1
				l1 = l1.next
			else:
				slide.next = l2
				l2 = l2.next
			slide = slide.next
		slide.next = l2 if l1 == None else l1
		return result.next

engine = Solution()
print engine.mergeTwoLists(None, None)
class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
		
class Solution(object):
	def rotateRight(self, head, k):
		if head == None:
			return None
		total = 1
		slide = head
		while slide.next:
			slide = slide.next
			total += 1
		slide.next = head
		for i in xrange(1, total - (k % total)):
			head = head.next
		slide = head.next
		head.next = None
		return slide
	
engine = Solution()
print engine.rotateRight(None, 1)
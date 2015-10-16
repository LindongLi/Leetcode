class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	minheap = list()
	def __pull_up(self, pos=1):
		if pos > len(self.minheap):
			return False
		flag = pos
		child = pos << 1
		if self.__pull_up(child) and self.minheap[flag - 1].val > self.minheap[child - 1].val:
			flag = child
		if self.__pull_up(child + 1) and self.minheap[flag - 1].val > self.minheap[child].val:
			flag = child + 1
		if flag != pos:
			self.minheap[flag - 1], self.minheap[pos - 1] = self.minheap[pos - 1], self.minheap[flag - 1]
			self.__push_down(flag)
		return True
	def __push_down(self, pos=1):
		flag = pos
		child = pos << 1
		if child <= len(self.minheap) and self.minheap[flag - 1].val > self.minheap[child - 1].val:
			flag = child
		if child < len(self.minheap) and self.minheap[flag - 1].val > self.minheap[child].val:
			flag = child + 1
		if flag != pos:
			self.minheap[flag - 1], self.minheap[pos - 1] = self.minheap[pos - 1], self.minheap[flag - 1]
			self.__push_down(flag)
	def mergeKLists(self, lists):
		for arr in lists:
			if arr is not None:
				self.minheap.append(arr)
		self.__pull_up()
		result = ListNode(0)
		slide = result
		while len(self.minheap) != 0:
			slide.next = self.minheap[0]
			slide = slide.next
			if slide.next:
				self.minheap[0] = slide.next
			else:
				self.minheap[0] = self.minheap[-1]
				self.minheap.pop()
			self.__push_down()
		return result.next

engine = Solution()
print engine.mergeKLists([ListNode(7), ListNode(5), ListNode(3)])
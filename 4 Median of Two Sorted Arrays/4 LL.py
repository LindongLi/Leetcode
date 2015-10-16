class Solution(object):
	@staticmethod
	def findKth(nums1, nums2, k):
		if len(nums1) == 0:
			return nums2[k - 1]
		if len(nums2) == 0:
			return nums1[k - 1]
		if k == 1:
			return min(nums1[0], nums2[0])
		pos1 = min(k >> 1, len(nums1) - 1)
		pos2 = min(max(0, k - pos1 - 2), len(nums2) - 1)
		pos1 = k - pos2 - 2
		if nums1[pos1] <= nums2[pos2]:
			if pos1 == len(nums1) - 1 or nums2[pos2] <= nums1[pos1 + 1]:
				return nums2[pos2]
			return Solution.findKth(nums1[pos1 + 1:], nums2, k - pos1 - 1)
		else:
			if pos2 == len(nums2) - 1 or nums1[pos1] <= nums2[pos2 + 1]:
				return nums1[pos1]
			return Solution.findKth(nums1, nums2[pos2 + 1:], k - pos2 - 1)

	def findMedianSortedArrays(self, nums1, nums2):
		answer = float(0)
		total = len(nums1) + len(nums2)
		if total != 0:
			if total & 0x1:
				answer += Solution.findKth(nums1, nums2, (total + 1) >> 1)
			else:
				answer += Solution.findKth(nums1, nums2, total >> 1)
				answer += Solution.findKth(nums1, nums2, (total >> 1) + 1)
				answer /= 2
		return answer

engine = Solution()
print engine.findMedianSortedArrays([1, 2], [0, 1])
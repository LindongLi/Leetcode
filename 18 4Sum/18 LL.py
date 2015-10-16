class Solution(object):
	def fourSum(self, nums, target):
		result = list()
		if(len(nums) < 4):
			return result
		values = []
		map = dict()
		for i in range(0, len(nums)):
			for j in range(i + 1, len(nums)):
				value = nums[i] + nums[j]
				if not map.has_key(value):
					values.append(value)
					map[value] = []
				map[value].append([i, j])
		values.sort()
		a = 0
		b = len(values) - 1
		while a <= b:
			if values[a] + values[b] < target:
				a += 1
			elif values[a] + values[b] == target:
				for ia in map[values[a]]:
					for ib in map[values[b]]:
						if ia[0] == ib[0] or ia[0] == ib[1]:
							continue
						if ia[1] == ib[0] or ia[1] == ib[1]:
							continue
						answer = sorted([nums[ia[0]], nums[ia[1]], nums[ib[0]], nums[ib[1]]])
						if answer not in result:
							result.append(answer)
				a += 1
			else:
				b -= 1
		return result

engine = Solution()
print engine.fourSum([0, 0, 0, 0], 0)
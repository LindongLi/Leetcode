class Solution(object):
	@staticmethod
	def fill(num, alpha):
		answer = str()
		if num == 9:
			answer += alpha[2]
			answer += alpha[0]
		elif num == 4:
			answer += alpha[2]
			answer += alpha[1]
		else:
			if num >= 5:
				num -= 5
				answer += alpha[1]
			if num >= 1:
				answer += alpha[2]
				if num >= 2:
					answer += alpha[2]
					if num >= 3:
						answer += alpha[2]
		return answer

	def intToRoman(self, num):
		result = str()
		result += Solution.fill((num / 1000) % 10, "  M")
		result += Solution.fill((num / 100) % 10, "MDC")
		result += Solution.fill((num / 10) % 10, "CLX")
		result += Solution.fill(num % 10, "XVI")
		return result

engine = Solution()
print engine.intToRoman(1207)
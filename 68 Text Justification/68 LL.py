class Solution(object):
    def fullJustify(self, words, maxWidth):
		wordcount = 0
		result = list()
		spaceleft = maxWidth
		for i in xrange(len(words)):
			if len(words[i]) >= spaceleft - wordcount:
				linecache = str()
				if wordcount == 1:
					
				avgspace = spaceleft / wordcount
				onespace = spaceleft % wordcount
				for j in xrange(onespace):
					linebuild += words[buildstart + j]
					linebuild += ' ' * (avgspace + 1)
				for j in xrange(onespace, wordcount):
					linebuild += words[buildstart + j]
					linebuild += ' ' * avgspace
				result.append(linebuild)
				buildstart = i
				spaceleft = maxWidth
			spaceleft -= len(words[i]) + 1
		return result

engine = Solution()
print engine.fullJustify(["aa", "bb"], 
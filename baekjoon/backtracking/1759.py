def check():
	vowelCnt = 0
	constCnt = 0
	printStr = ''
	for i in range(len(l)):
		if li[i]:
			printStr += l[i]
			if l[i] in vowels:
				vowelCnt += 1
			else:
				constCnt += 1
	if vowelCnt >= 1 and constCnt >= 2:
		print(printStr)

def get_password(s, n):
	if n == L:
		check()
		return
	for i in range(s, len(l)):
		if li[i]: continue
		li[i] = 1
		get_password(i+1, n+1)
		li[i] = 0

L, C = list(map(int, input().split()))
l = input().split()
l.sort()
li = [0] * len(l)

vowels = ['a', 'e', 'i', 'o', 'u']

get_password(0, 0)

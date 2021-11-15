import sys

cur = 100
minVal = 0

def getLen(num):
	return len(str(num))

def checkAvail(num, availBtn):
	for i in str(num):
		if int(i) not in availBtn:
			return False
	return True

def getCnt(num, N, availBtn):
	if checkAvail(num, availBtn):
		return getLen(num) + abs(num - N)
	return -1


if __name__=="__main__":
	availBtn = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
	N = int(input())
	c = input()
	il = []
	if c != '0':
		il = input().split()
	
	fb = list(map(int, il))
	availBtn = [itm for itm in availBtn if itm not in fb]

	minVal = abs(cur - N)

	for i in range(0, 1000001):
		cnt = getCnt(i, N, availBtn)
		if cnt == -1:
			continue
		if cnt < minVal:
			minVal = cnt
	print(minVal)

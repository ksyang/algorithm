while True:
	stack = []
	H = input()
	if H == '#':
		break
	
	iligFlag = 0
	for idx, v in enumerate(H):
		if v == '<':
			endIdx = H.find('>', idx)
			if H[endIdx-1] == '/': continue
			if H[idx+1] == '/':
				if len(stack) == 0 or stack.pop() != H[idx+2:endIdx]:
					iligFlag = 1
					break
			else:
				splitIdx = H[idx+1:endIdx].find(' ')
				if splitIdx != -1: endIdx = splitIdx+1
				stack.append(H[idx+1:endIdx])

	if iligFlag == 1 or len(stack) != 0:
		print('illegal')
	else:
		print('legal')

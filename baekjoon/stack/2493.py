n = int(input())

top = list(map(int, input().split()))

stack = []

for idx, v in enumerate(top):
	while len(stack) != 0 and stack[-1][1] <= v:
		stack.pop()
	if len(stack) == 0:
		print(0, end=' ')
		stack.append([idx, v])
	else:
		print(stack[-1][0]+1, end=' ')
		stack.append([idx, v])

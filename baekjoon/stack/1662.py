Sstack = []
Rstack = []

S = input()
lazyPos = 0
length = 0
mulV = 0

for i in S:
	if i.isdigit():
		length += 1
		mulV = int(i)
	if i == '(':
		Rstack.append(mulV)
		Sstack.append(length-1)
		length = 0
	elif i == ')':
		length = length * Rstack.pop() + Sstack.pop()

print(length)

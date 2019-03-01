TEXT = input()
DATA = TEXT.split(" ")

V = {}
D = {}

CAP = []
CAP.append(int(DATA[0]))
CAP.append(int(DATA[1]))

C = []
C.append(int(DATA[2]))
C.append(int(DATA[3]))

Q = []
D[(0,0)] = 0
V[(0,0)] = True
ans = -1
Q.append([0,0])
while not(len(Q) == 0):
	tmp = Q[0]
	del Q[0]
	A = tmp[0]
	B = tmp[1]

	if A == C[0] and B == C[1]:
		ans = D[(A, B)]
		break
	#A -> 0
	if not((0, B) in V):
		V[(0, B)] = True
		D[(0, B)] = D[(A, B)] + 1
		Q.append([0, B])
	#A -> Full
	if not((CAP[0], B) in V):
		V[(CAP[0], B)] = True
		D[(CAP[0], B)] = D[(A, B)] + 1
		Q.append([CAP[0], B])
	#B - > 0
	if not((A, 0) in V):
		V[(A, 0)] = True
		D[(A, 0)] = D[(A, B)] + 1
		Q.append([A, 0])
	#V -> Full
	if not((A, CAP[1]) in V):
		V[(A, CAP[1])] = True
		D[(A, CAP[1])] = D[(A, B)] + 1
		Q.append([A, CAP[1]])

	#A -> B
	if A + B <= CAP[1] and not((0, A + B) in V):
		V[(0, A + B)] = True
		D[(0, A + B)] = D[(A,B)] + 1
		Q.append([0, A + B])

	if CAP[1] - B < A:
		temp = A - (CAP[1] - B)
		if not((temp, CAP[1]) in V):
			V[(temp, CAP[1])] = True
			D[(temp, CAP[1])] = D[(A,B)] + 1
			Q.append([temp,CAP[1]])

	#B -> A
	if A + B <= CAP[0] and not((A + B, 0) in V):
		V[(A + B, 0)] = True
		D[(A + B, 0)] = D[(A,B)] + 1
		Q.append([A + B, 0])

	if CAP[0] - A < B:
		temp = B - (CAP[0] - A)
		if not((CAP[0], temp) in V):
			V[(CAP[0], temp)] = True
			D[(CAP[0], temp)] = D[(A,B)] + 1
			Q.append([CAP[0], temp])

print(ans)

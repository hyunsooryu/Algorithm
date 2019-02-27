
text = input()
N = int(text.split(" ")[0])
M = int(text.split(" ")[1])
target = int(input())


T = max(N, M)

V = [[False] * (T + 1) for i in range(T + 1)]

def possible(i, j):
	if i >= 0 and j >= 0 and i <= N and j <= M:
		return True
	else:
		return False

def BFS():
	Q = []
	Q.append([0,0])
	while len(Q) > 0:
		top = Q[0]
		del Q[0]

		A = top[0]
		B = top[1]

		if A == target or B == target:
			return True

		if V[A][0] == False and possible(A, 0):
			V[A][0] = True
			Q.append([A, 0])

		if V[0][B] == False and possible(0, B):
			V[0][B] = True
			Q.append([0, B])

		if V[N][B] == False and possible(N, B):
			V[N][B] = True
			Q.append([N, B])

		if V[A][M] == False and possible(A, M):
			V[A][M] = True
			Q.append([A, M])

		if  A >= M - B:
			if V[A - (M - B)][M] == False and possible(A - (M - B),M) ==True:
				V[A - (M - B)][M] = True
				Q.append([A - (M - B), M])

		else:
			if not(V[0][B + A]):
				V[0][B + A] = True;
				Q.append([0, B + A])



		if B >= N - A:
			if V[N][B - (N - A)] == False and possible(N, B - (N - A)) == True:
				V[N][B - (N - A)] = True
				Q.append([N, B - (N - A)])


		else:
			if not(V[0][B + A]):
				V[0][B + A] = True
				Q.append(0, B + A)

	return False

if BFS() == True:
	print("True")
else:
	print("False")

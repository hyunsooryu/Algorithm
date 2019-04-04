A = [0] * 10
print(A)
V = [False] * 10
print(V)
def go(index, n, m):
    if index == m:
        for i in range(m):
            print(A[i], end = " ")
        print()
        return
    for i in range(1, n + 1):
        if V[i]:
            continue
        V[i] = True
        A[index] = i
        go(index + 1, n, m)
        V[i] = False


N, M = input().split()
go(0, int(N), int(M))


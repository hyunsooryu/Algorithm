V = [False] * 10
path = [0] * 10
A = 0
def go(index, n, m):
    if index == m:
        for i in range(m):
            print(path[i], end = " ")
        print()
        return
    for i in range(n):
        if V[i]:
            continue
        V[i] = True
        path[index] = A[i]
        go(index + 1, n, m)
        V[i] = False
n, m = input().split()
A = [int(x) for x in input().split()]
print(A)
A.sort()
go(0, int(n), int(m))


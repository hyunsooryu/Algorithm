A = [0] * 10
def go(index, start, n, m):
    if index == m:
        for i in range(m):
            print(A[i], end = " ")
        print()
        return
    
    for i in range(start, n + 1):
        A[index] = i
        go(index + 1, i, n, m)



n,m = input().split()

go(0, 1, int(n), int(m))


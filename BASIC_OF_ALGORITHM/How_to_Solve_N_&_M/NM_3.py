A = [0] * 10
def go(index, n, m):
    if index == m:
        for i in range(m):
            print(A[i], end = " ")
        print() 
        return
    
    for i in range(1, n + 1):
        A[index] = i
        go(index + 1, n, m)
N, M = input().split()
go(0, int(N), int (M))

#FOR문의 연산과 비슷하군요


    
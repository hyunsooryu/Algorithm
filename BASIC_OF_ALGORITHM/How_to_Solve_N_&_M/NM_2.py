A = [0] * 10 #오름차순에서는 V가 없어도 됩니다..
V = [False] * 10
def go(index, start, n, m):
    if index == m: #index 0 ~ m-1이 다차있다 라는 말입니다.
        for i in range(m):
            print(A[i], end = " ")
        print()
        return
    for i in range(start, n + 1):
       # if V[i]:
        #    continue
      #  V[i] = True
        A[index] = i
        go(index + 1, i + 1, n, m)
       # V[i] = False
    

N, M = input().split()

go(0, 1, int(N), int(M))

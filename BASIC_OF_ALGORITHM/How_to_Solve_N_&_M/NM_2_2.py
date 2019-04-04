a = [0] * 10

def go(i, size, n, m):
    if size == m:
        for k in range(m):
            print(a[k], end = " ")
        print()
        return
    
    if i > n:
        return
    a[size] = i
    go(i + 1, size + 1, n, m)
    go(i + 1, size, n, m)

n, m = input().split()

go(1, 0, int(n), int(m))

    

    
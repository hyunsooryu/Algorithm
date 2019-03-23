import sys
sys.setrecursionlimit(100000)

def convertBinary(n) :
    if n == 0:
        return ''
    mok = int(n / 2)
    na = int(n % 2)
    tmp = convertBinary(mok)
    return tmp + str(na)

def main():
    '''
    이 부분은 수정하지 마세요.
    '''
    n = int(input())

    print(convertBinary(n))

if __name__ == "__main__":
    main()

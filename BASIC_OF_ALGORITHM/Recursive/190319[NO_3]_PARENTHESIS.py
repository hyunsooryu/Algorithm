def checkParen(p):
    if(len(p) % 2 == 1):
        return "NO"
    print(p)
    flag = "NO"
    if(len(p) == 2):
        print(p)
        if (p[0] == '(') and (p[-1] == ')'):
            return "YES"
        return "NO"
    

    if (p[0] == '(') and (p[-1] == ')'):
        tmp = checkParen(p[1:-1])
        if tmp == "YES":
            flag = tmp
    k = 1
    while True:
        if k >= len(p) - 1:
            break
        left = checkParen(p[ :k + 1])
        right = checkParen(p[k + 1:])
        if (left == "YES") and (right == "YES"):
            flag = "YES"
        k += 2
    return flag

def main():

    x = input()
    print(checkParen(x))

if __name__ == "__main__":
    main()



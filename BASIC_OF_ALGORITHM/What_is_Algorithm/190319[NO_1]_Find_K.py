def findKth(myInput, k) :
    result = []
    tmp = []
    size = len(myInput)
    for i in range(0, size):
        if i < k - 1:
            result.append(-1)
            tmp.append(myInput[i])
        else:
            tmp.append(myInput[i])
            tmp.sort()
            result.append(tmp[k - 1])
    return result

def main():
   
    firstLine = [int(x) for x in input().split()]
    myInput = [int(x) for x in input().split()]

    print(*findKth(myInput, firstLine[1]))
if __name__ == "__main__":
    main()

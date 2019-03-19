def quickSort(array):
    if len(array) <= 1:
        return array
    pivot = array[0]
    center = [pivot]
    left = []
    right = []
    for i in range(1, len(array)):
        if array[i] > pivot:
            right.append(array[i])
        else:
            left.append(array[i])
    return quickSort(left) + center + quickSort(right)
def main():
    line = [int(x) for x in input().split()]
    ans = quickSort(line)
    for i in ans:
        print(i, end = " ")
if __name__ == "__main__":
    main()

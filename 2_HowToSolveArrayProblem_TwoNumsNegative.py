
def maxTwoDiff(nums):
    MAX = nums[0]
    MIN = nums[0]
    for i in nums:
        if i > MAX:
            MAX = i
        if i < MIN:
            MIN = i
        
    return MAX - MIN

def main():
    print(maxTwoDiff([2, 8, 19, 37, 4, 5, 12, 50, 1, 34, 23])) # should return 49

if __name__ == "__main__":
    main()


def maxSubArray(nums):
    D = [0] * len(nums);
    D[0] = nums[0]
    for i in range(1, len(nums)):
        D[i] = nums[i]
        if D[i - 1] + nums[i] > nums[i]:
            D[i] = D[i - 1] + nums[i]
    return max(D)

def main():
    print(maxSubArray([-10, -7, 5, -7, 10, 5, -2, 17, -25, 1])) # 30이 리턴되어야 합니다

if __name__ == "__main__":
    main()
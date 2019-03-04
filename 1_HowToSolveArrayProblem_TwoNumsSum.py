
def twoSum(nums, target):
    nums.sort()
    S = 0;
    E = len(nums) - 1
    while S < E:
        if nums[S] + nums[E] == target:
            return (nums[S], nums[E])
        elif nums[S] + nums[E] < target:
            S += 1
        else:
            E -= 1

def main():
    print(twoSum([2, 8, 19, 37, 4, 5], 12))

if __name__ == "__main__":
    main()

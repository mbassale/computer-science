from typing import List


def reverse(nums: List[int], leftIdx: int, rightIdx: int) -> None:
    while leftIdx < rightIdx:
        nums[leftIdx], nums[rightIdx] = nums[rightIdx], nums[leftIdx]
        leftIdx += 1
        rightIdx -= 1


def rotate(nums: List[int], k: int) -> None:
    k = k % len(nums)
    if k > 0:
        reverse(nums, 0, len(nums) - 1)
        reverse(nums, 0, k - 1)
        reverse(nums, k, len(nums) - 1)


def runTestCase(nums: List[int], k: int) -> None:
    origList = ",".join([str(n) for n in nums])
    rotate(nums, k)
    rotatedList = ",".join([str(n) for n in nums])
    print(f"{origList}, k={k} => {rotatedList}")


if __name__ == "__main__":
    runTestCase([1], 0)
    runTestCase([1], 10)
    runTestCase([1, 2], 1)
    runTestCase([1, 2], 2)
    runTestCase([1, 2], 3)
    runTestCase([1, 2, 3, 4, 5, 6, 7], 3)

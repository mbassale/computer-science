from typing import List


def removeDuplicates(nums: List[int]) -> None:
    insertIdx = 1
    i = 1
    while insertIdx < len(nums) and i < len(nums):
        while i < len(nums) and nums[insertIdx - 1] == nums[i]:
            i += 1
        if i < len(nums):
            nums[insertIdx] = nums[i]
            insertIdx += 1
            i += 1
    return insertIdx


def runTestCase(nums: List[int]) -> None:
    origList = ",".join([str(n) for n in nums])
    k = removeDuplicates(nums)
    newList = ",".join([str(n) for n in nums[:k]])
    print("%s => %s k=%d" % (origList, newList, k))


if __name__ == "__main__":
    runTestCase([1])
    runTestCase([1, 1])
    runTestCase([1, 1, 1, 1, 1, 1, 1, 1])
    runTestCase([1, 1, 1, 1, 1, 1, 1, 1, 1, 2])
    runTestCase([1, 2])
    runTestCase([1, 2, 2, 2, 2, 2, 2, 2])
    runTestCase([1, 2, 2, 2, 2, 2, 2, 2, 2, 3])
    runTestCase([1, 2, 3, 3, 4, 5, 5, 5, 6])

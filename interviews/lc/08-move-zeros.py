from typing import List
import time


def moveZeroes(nums: List[int]) -> None:
    insertionIdx = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[insertionIdx], nums[i] = nums[i], nums[insertionIdx]
            insertionIdx += 1


def runTestCase(nums: List[int]) -> None:
    numsStr = ",".join([str(n) for n in nums])
    start = time.perf_counter_ns()
    moveZeroes(nums)
    end = time.perf_counter_ns()
    resultStr = ",".join([str(n) for n in nums])
    delta = end - start
    print(f"{numsStr} => {resultStr} {delta}ns")


if __name__ == "__main__":
    runTestCase([0, 0, 0, 0, 1])
    runTestCase([0, 0, 0, 1, 2])
    runTestCase([1, 2, 3])
    runTestCase([0, 1, 0, 3, 12])
    runTestCase([0])

import time
from typing import List


def twoSum(nums: List[int], target: int) -> tuple[int, int]:
    seen: dict[int, int] = {}
    for i in range(len(nums)):
        diff = target - nums[i]
        if diff in seen:
            idx1 = seen[diff]
            return (idx1, i)
        seen[nums[i]] = i
    return (-1, -1)


def runTestCase(nums: List[int], target: int) -> None:
    numsStr = ",".join([str(n) for n in nums])
    start = time.perf_counter_ns()
    idx1, idx2 = twoSum(nums, target)
    end = time.perf_counter_ns()
    delta = end - start
    print(f"{numsStr}, {target} => ({idx1}, {idx2}) {delta}ns")


if __name__ == "__main__":
    runTestCase([2, 7, 11, 15], 9)
    runTestCase([3, 2, 4], 6)
    runTestCase([3, 3], 6)

from typing import List
import time


def singleNumberHash(nums: List[int]) -> int:
    freqs = {}
    for i in nums:
        if i in freqs:
            freqs[i] += 1
        else:
            freqs[i] = 1
    for k, v in freqs.items():
        if v == 1:
            return k
    assert False, "Unreachable"


def singleNumberMath(nums: List[int]) -> int:
    """
    2 * (a + b + c) - (a + a + b + b + c) = c
    """
    return 2 * sum(set(nums)) - sum(nums)


def singleNumberXor(nums: List[int]) -> int:
    result = 0
    for n in nums:
        result ^= n
    return result


def runTestCase(nums: List[int], expected: int) -> None:
    numsStr = ",".join([str(n) for n in nums])
    start = time.perf_counter_ns()
    result = singleNumberHash(nums)
    end = time.perf_counter_ns()
    delta = end - start
    print(f"{numsStr} => Actual: {result}, Expected: {expected} {delta}ns")

    start = time.perf_counter_ns()
    result = singleNumberMath(nums)
    end = time.perf_counter_ns()
    delta = end - start
    print(f"{numsStr} => Actual: {result}, Expected: {expected} {delta}ns")

    start = time.perf_counter_ns()
    result = singleNumberXor(nums)
    end = time.perf_counter_ns()
    delta = end - start
    print(f"{numsStr} => Actual: {result}, Expected: {expected} {delta}ns")


if __name__ == "__main__":
    runTestCase([2, 2, 1], 1)
    runTestCase([4, 1, 2, 1, 2], 4)
    runTestCase([1], 1)
    runTestCase([1, 2, 3, 1, 2, 3, 4], 4)

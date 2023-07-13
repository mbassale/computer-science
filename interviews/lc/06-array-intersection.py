from typing import List
import time


def intersectHash(nums1: List[int], nums2: List[int]) -> List[int]:
    nums1Freqs = {}
    for n in nums1:
        if n in nums1Freqs:
            nums1Freqs[n] += 1
        else:
            nums1Freqs[n] = 1
    result = []
    for n in nums2:
        if n in nums1Freqs and nums1Freqs[n] > 0:
            result.append(n)
            nums1Freqs[n] -= 1
    return result


def intersectSort(nums1: List[int], nums2: List[int]) -> List[int]:
    nums1.sort()
    nums2.sort()
    ptr1Idx = 0
    ptr2Idx = 0
    result = []
    while ptr1Idx < len(nums1) and ptr2Idx < len(nums2):
        n1 = nums1[ptr1Idx]
        n2 = nums2[ptr2Idx]
        if n1 == n2:
            result.append(n1)
            ptr1Idx += 1
            ptr2Idx += 1
        elif n1 < n2:
            ptr1Idx += 1
        else:  # n1 > n2
            ptr2Idx += 1
    return result


def runTestCase(nums1: List[int], nums2: List[int]) -> None:
    nums1Str = ",".join([str(n) for n in nums1])
    nums2Str = ",".join([str(n) for n in nums2])
    start = time.perf_counter_ns()
    result = intersectHash(nums1, nums2)
    end = time.perf_counter_ns()
    resultStr = ",".join([str(n) for n in result])
    delta = end - start
    print(f"intersectHash: {nums1Str} & {nums2Str} = {resultStr} {delta}ns")

    nums1Str = ",".join([str(n) for n in nums1])
    nums2Str = ",".join([str(n) for n in nums2])
    start = time.perf_counter_ns()
    result = intersectSort(nums1, nums2)
    end = time.perf_counter_ns()
    resultStr = ",".join([str(n) for n in result])
    delta = end - start
    print(f"intersectSort: {nums1Str} & {nums2Str} = {resultStr} {delta}ns")


if __name__ == "__main__":
    runTestCase([1], [1])
    runTestCase([1], [2])
    runTestCase([1, 2, 2, 1], [2, 2])
    runTestCase([4, 9, 5, 4], [9, 4, 9, 8, 4])

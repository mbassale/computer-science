#
# [Sedgewick][Ch1][Python] Exercise 1.4.14 4-Sum with sorting.
#
# python3 ex-1.4.14-4-sum.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


def two_sum_sorted(arr: list[int], start: int, target: int) -> list[list[int]]:
    left = start
    right = len(arr) - 1
    result = []
    while left < right:
        s = arr[left] + arr[right]
        if s == target:
            result.append([arr[left], arr[right]])
            left += 1
            right -= 1
        elif s < target:
            left += 1
        else:
            right -= 1
    return result


def k_sum(arr: list[int], start: int, k: int, target: int) -> list[list[int]]:
    # we run out of elements
    if start == len(arr):
        return []
    # linear two sum on the rest of the array
    if k == 2:
        return two_sum_sorted(arr, start, target)
    result = []
    for i in range(len(arr)):
        current = arr[i]
        diff = target - current
        if diff < 0:
            continue
        k_minus_1_result = k_sum(arr, i + 1, k - 1, diff)
        for k_minus_1 in k_minus_1_result:
            # as the numbers are sorted, prevent repeating results
            if current >= k_minus_1[0]:
                continue
            result.append([current] + k_minus_1)
    return result


def four_sum(arr: list[int], target: int) -> list[list[int]]:
    arr.sort()
    return k_sum(arr, 0, 4, target)


class FourSumTest(unittest.TestCase):
    def test_four_sum(self):
        test_cases = [
            ([1, 2, 3, 4], 4, []),
            ([1, 2, 3, 4], 10, [[1, 2, 3, 4]]),
            ([1, 2, 3, 4, 5, 6], 14, [[1, 2, 5, 6], [1, 3, 4, 6], [2, 3, 4, 5]]),
        ]
        for arr, target, expected in test_cases:
            expected.sort()
            self.assertListEqual(
                four_sum(arr, target), expected, f"Expected: {expected}"
            )


if __name__ == "__main__":
    unittest.main()

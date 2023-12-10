#
# [Sedgewick][Ch1][Python] Exercise 1.4.15 Faster 3-sum for sorted arrays.
#
# $ python3 ex-1.4.15-faster-3-sum.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


def two_sum(arr: list[int], start: int, target: int) -> list[list[int]]:
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


def faster_3_sum(arr: list[int], target: int) -> list[list[int]]:
    result = []
    for i in range(len(arr) - 2):
        current = arr[i]
        diff = target - current
        two_sum_result = two_sum(arr, i + 1, diff)
        for two_sum_pairs in two_sum_result:
            # as the numbers are sorted, prevent repeating results
            if current > two_sum_pairs[0]:
                continue
            result.append([current] + two_sum_pairs)
    return result


class Faster3SumTest(unittest.TestCase):
    def test_faster_3_sum(self):
        test_cases = [
            ([], 100, []),
            ([1, 2, 3], 10, []),
            ([1, 2, 3], 6, [[1, 2, 3]]),
            (
                [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
                10,
                [[1, 2, 7], [1, 3, 6], [1, 4, 5], [2, 3, 5]],
            ),
        ]
        for arr, target, expected in test_cases:
            self.assertListEqual(
                faster_3_sum(arr, target), expected, f"Arr: {arr}, Target: {target}"
            )


if __name__ == "__main__":
    unittest.main()

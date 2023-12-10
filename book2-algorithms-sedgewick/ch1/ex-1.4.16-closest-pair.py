#
# [Sedgewick][Ch1][Python] Exercise 1.4.16 Closest Pair with sorted array.
#
# $ python3 ex-1.4.16-closest-pair.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest
import sys


def closest_pair(arr: list[int]) -> (int, int):
    if len(arr) < 2:
        return (None, None)
    if len(arr) == 2:
        return (arr[0], arr[1])

    min_diff = sys.maxsize
    min_pair = (None, None)
    for i in range(1, len(arr)):
        diff = arr[i] - arr[i - 1]
        if diff < min_diff:
            min_diff = diff
            min_pair = (arr[i - 1], arr[i])

    return min_pair


class ClosestPairTest(unittest.TestCase):
    def test_closest_pair(self):
        test_cases = [
            ([1, 1], (1, 1)),
            ([1, 3, 99, 100], (99, 100)),
            ([1, 4, 8, 16, 32, 64, 128, 256], (1, 4)),
        ]
        for arr, expected in test_cases:
            self.assertEqual(closest_pair(arr), expected, f"Arr: {arr}")


if __name__ == "__main__":
    unittest.main()

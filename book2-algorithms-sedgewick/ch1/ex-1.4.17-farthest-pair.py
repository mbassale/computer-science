#
# [Sedgewick][Ch1][Python] Exercise 1.4.17 Farthest Pair in linear time.
#
# $ python3 ex-1.4.17-farthest-pair.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest
import sys


def farthest_pair(arr: list[int]) -> (int, int):
    if len(arr) < 2:
        return (None, None)
    if len(arr) == 2:
        return (arr[0], arr[1])

    return (min(arr), max(arr))


class FarthestPairTest(unittest.TestCase):
    def test_farthest_pair(self):
        test_cases = [
            ([1, 1], (1, 1)),
            ([1, 3, 99, 100, 197], (1, 197)),
            ([1, 4, 8, 16, 32, 64, 128, 256], (1, 256)),
        ]
        for arr, expected in test_cases:
            self.assertEqual(farthest_pair(arr), expected, f"Arr: {arr}")


if __name__ == "__main__":
    unittest.main()

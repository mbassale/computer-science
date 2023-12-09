#
# [Sedgewick][Ch1][Python] Exercise 1.4.10 Binary Search Smallest Index
#
# $ python3 ex-1.4.10-binary-search-smallest-index.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


def binary_search_first_ocurrence(
    a: list[int],
    target: int,
) -> int:
    left = 0
    right = len(a) - 1
    result = -1

    while left <= right:
        mid = left + (right - left) // 2

        # if we found the key, keep searching to the left
        if a[mid] == target:
            result = mid
            right = mid - 1
        elif a[mid] < target:
            right = mid - 1
        else:
            left = mid + 1

    return result


class BinarySearchFirstOcurrence(unittest.TestCase):
    def test_binary_search_first_ocurrence(self):
        test_cases = [
            ([], 1, -1),
            ([1], 1, 0),
            ([1, 1, 1, 1], 1, 0),
            ([1, 1, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10], 5, 6),
            ([1, 1, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10], 25, -1),
        ]
        for arr, target, expected in test_cases:
            self.assertEqual(binary_search_first_ocurrence(arr, target), expected)


if __name__ == "__main__":
    unittest.main()

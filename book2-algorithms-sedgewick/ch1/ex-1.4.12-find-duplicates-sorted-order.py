#
# [Sedgewick][Ch1][Python] Exercise 1.4.12 Find Duplicates in Sorted Order
#
# python3 ex-1.4.12-find-duplicates-sorted-order.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


def find_duplicates_sorted_order(arr1: list[int], arr2: list[int]) -> list[int]:
    result = []
    i1 = 0
    i2 = 0
    while i1 < len(arr1) and i2 < len(arr2):
        while i1 < len(arr1) and i2 < len(arr2) and arr1[i1] == arr2[i2]:
            if len(result) == 0 or result[-1] != arr1[i1]:
                result.append(arr1[i1])
            i1 += 1
            i2 += 1
        if i1 >= len(arr1) or i2 >= len(arr2):
            break
        if arr1[i1] < arr2[i2]:
            i1 += 1
        elif arr1[i1] > arr2[i2]:
            i2 += 1

    return result


class FindDuplicatesSortedOrderTest(unittest.TestCase):
    def test_find_duplicates_sorted_order(self):
        test_cases = [
            ([1], [1], [1]),
            ([1, 2, 3], [1, 2, 3], [1, 2, 3]),
            ([1, 2, 3, 3, 3], [1, 2, 3], [1, 2, 3]),
            ([1, 2, 3], [4, 5, 6], []),
            ([1, 2, 2, 3], [2, 2], [2]),
        ]
        for arr1, arr2, expected in test_cases:
            self.assertEqual(
                find_duplicates_sorted_order(arr1, arr2),
                expected,
                f"TestCase: {expected}",
            )


if __name__ == "__main__":
    unittest.main()

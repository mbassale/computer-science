#
# [Sedgewick][Ch1][Python] Exercise 1.4.18 Local Minimum of an Array, Linearithmic Time.
#
# $ python3 ex-1.4.18-local-minimum-array.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


def find_local_minimum(arr: list[int]) -> int:
    def binary_search(left: int, right: int) -> int:
        if left == right:
            return left

        mid = left + (right - left) // 2
        if (mid == 0 or arr[mid - 1] > arr[mid]) and (
            mid == len(arr) - 1 or arr[mid + 1] > arr[mid]
        ):
            return mid

        if mid > 0 and arr[mid - 1] < arr[mid]:
            return binary_search(left, mid - 1)
        else:
            return binary_search(mid + 1, right)

    return binary_search(0, len(arr) - 1)


class FindLocalMinimumTest(unittest.TestCase):
    def test_find_local_minimum(self):
        test_cases = [
            ([1, 1], 1),
            ([1, 0, 1], 1),
            ([0, 1], 0),
            ([1, 0], 1),
            ([1, 0, 1, -1], 1),
            ([10, 5, 3, 6, 13, 16, 7], 2),
        ]
        for arr, expected in test_cases:
            self.assertEqual(
                find_local_minimum(arr), expected, f"Arr: {arr} Expected: {expected}"
            )


if __name__ == "__main__":
    unittest.main()

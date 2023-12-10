#
# [Sedgewick][Ch1][Python] Exercise 1.4.20 Bitonic Search. Logarithmic Time.
#
# $ python3 ex-1.4.20-bitonic-search.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


def bitonic_search(arr: list[int], key: int) -> int:
    def find_bitonic_point() -> int:
        left = 0
        right = len(arr) - 1
        while left <= right:
            mid = left + (right - left) // 2
            # bitonic point
            if (mid == 0 or arr[mid - 1] < arr[mid]) and (
                mid == len(arr) - 1 or arr[mid] > arr[mid + 1]
            ):
                return mid
            # decreasing side, need to search at left
            elif mid > 0 and arr[mid - 1] > arr[mid]:
                right = mid - 1
            # increasing side, need to search at right
            else:
                left = mid + 1
        return -1

    def binary_search(left: int, right: int, ascending=True) -> int:
        while left <= right:
            mid = left + (right - left) // 2
            if arr[mid] == key:
                return mid

            # increasing side
            if ascending:
                if arr[mid] < key:
                    left = mid + 1
                else:
                    right = mid - 1
            # decreasing side
            else:
                if arr[mid] < key:
                    right = mid - 1
                else:
                    left = mid + 1
        return -1

    bitonic_pos = find_bitonic_point()
    if bitonic_pos == -1:
        return -1
    if arr[bitonic_pos] == key:
        return bitonic_pos

    key_pos = binary_search(0, bitonic_pos - 1, ascending=True)
    if key_pos != -1:
        return key_pos
    return binary_search(bitonic_pos + 1, len(arr) - 1, ascending=False)


class BitonicSearchTest(unittest.TestCase):
    def test_bitonic_search(self):
        test_cases = [
            ([1], 2, -1),
            ([1], 1, 0),
            ([1, 2], 3, -1),
            ([1, 2], 2, 1),
            ([1, 2, 3, 2, 1], 1, 0),
            ([1, 10, 11, 12, 13, 14, 15, 9, 8, 7, 6, 5], 7, 9),
        ]
        for arr, key, expected_pos in test_cases:
            self.assertEqual(
                bitonic_search(arr, key),
                expected_pos,
                f"Arr: {arr}, Key: {key}, ExpectedPos: {expected_pos}",
            )


if __name__ == "__main__":
    unittest.main()

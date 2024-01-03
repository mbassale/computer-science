#
# [Sedgewick][Ch2][Rust] Exercise 2.2.18 Shuffle List.
# Using merge sort as base, created a simple shuffle algorithm for a list of integers.
#
# $ python3 ex-2.2.18-shuffle-linked-list.py
# []
# []
# [1]
# [1]
# [1, 2]
# [2, 1]
# [1, 2, 3]
# [1, 3, 2]
# [1, 2, 3, 4]
# [4, 3, 2, 1]
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
# [12, 19, 8, 9, 18, 14, 6, 5, 13, 7, 10, 4, 1, 17, 11, 16, 3, 15, 0, 2]
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.197s
#
# OK
#


import unittest
import random

def shuffle_list(arr: list[int]) -> list[int]:

    def shuffle_sub_array(arr: list[int], aux: list[int], lo: int, mid: int, hi: int):
        for k in range(lo, hi + 1):
            aux[k] = arr[k]

        i = lo
        j = mid + 1
        for k in range(lo, hi + 1):
            if i > mid:
                arr[k] = aux[j]
                j += 1
            elif j > hi:
                arr[k] = aux[i]
                i += 1
            else:
                if random.random() < 0.5:
                    arr[k] = aux[i]
                    i += 1
                else:
                    arr[k] = aux[j]
                    j += 1

    def shuffle_impl(arr: list[int], aux: list[int], lo: int, hi: int) -> list[int]:
        if lo >= hi:
            return arr
        mid = lo + (hi - lo) // 2
        shuffle_impl(arr, aux, lo, mid)
        shuffle_impl(arr, aux, mid + 1, hi)
        shuffle_sub_array(arr, aux, lo, mid, hi)
        return arr

    aux = arr[:]
    shuffle_impl(arr, aux, 0, len(arr) - 1)
    return arr




class ShuffleListTest(unittest.TestCase):
    def test_shuffle_list(self):
        test_cases = [
            [],
            [1],
            [1,2],
            [1, 2, 3],
            [1, 2, 3, 4],
            [i for i in range(0, 20)],
            [random.randint(0, 10000) for _ in range(0, 100000)]
        ]
        for test_case in test_cases:
            result = shuffle_list(test_case[:])
            if len(test_case) < 50:
                print(test_case)
                print(result)
            self.assertEqual(sorted(test_case), sorted(result))

if __name__ == "__main__":
    unittest.main()

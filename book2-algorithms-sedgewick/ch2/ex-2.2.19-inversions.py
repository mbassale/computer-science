import unittest

def number_inversions(arr: list[int]) -> int:

    def merge(arr: list[int], aux: list[int], lo: int, mid: int, hi: int) -> int:
        i = lo
        j = mid
        k = lo
        inv_count = 0
        while i < mid and j <= hi:
            if arr[i] <= arr[j]:
                aux[k] = arr[i]
                i += 1
            else:
                aux[k] = arr[j]
                j += 1
                # all elements to the right of i are out of place
                inv_count += mid - i
            k += 1

        # copy remainder elements of left sub array
        while i < mid:
            aux[k] = arr[i]
            i += 1
            k += 1

        # copy remainder elements of right sub array
        while j <= hi:
            aux[k] = arr[j]
            j += 1
            k += 1


        # copy from auxiliary sub array to the original sub array
        for k in range(lo, hi + 1):
            arr[k] = aux[k]

        return inv_count


    def merge_sort_impl(arr: list[int], aux: list[int], lo: int, hi: int) -> int:
        if lo >= hi:
            return 0

        mid = lo + (hi - lo) // 2
        inv = merge_sort_impl(arr, aux, lo, mid)
        inv += merge_sort_impl(arr, aux, mid + 1, hi)
        inv += merge(arr, aux, lo, mid + 1, hi)
        return inv


    aux = arr[:]
    return merge_sort_impl(arr, aux, 0, len(arr) - 1)

class InversionsTest(unittest.TestCase):

    def test_inversions(self):
        test_cases = [
            ([], 0),
            ([1], 0),
            ([1,2], 0),
            ([1,2,3], 0),
            ([3,2,1], 3),
            ([2, 4, 1, 3, 5], 3),
        ]
        for test_case, expected in test_cases:
            actual = number_inversions(test_case)
            self.assertEqual(expected, actual)

if __name__ == "__main__":
    unittest.main()


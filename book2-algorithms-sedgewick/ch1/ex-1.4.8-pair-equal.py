#
# [Sedgewick][Ch1][Python] Exercise 1.4.8 Duplicate Pairs
#
# $ python3 ex-1.4.8-pair-equal.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.300s
#
# OK
#
import random
import unittest


def find_duplicates(a: list[int]) -> int:
    a.sort()
    duplicate_count = 0
    for i in range(1, len(a)):
        if a[i] == a[i - 1]:
            duplicate_count += 1
    return duplicate_count


class TestFindDuplicates(unittest.TestCase):
    def gen_random(self, n: int) -> list[int]:
        return [random.randint(1, 100) for _ in range(n)]

    def test_find_duplicates(self):
        test_cases = [
            ([1], 0),
            ([1, 1], 1),
            ([1, 1, 1], 2),
            ([1, 1, 1, 1], 3),
            ([9, 8, 8, 7, 6, 5, 5, 5, 4, 3, 1, 1], 4),
        ]
        for a, expected in test_cases:
            self.assertEqual(find_duplicates(a), expected)

        # for 100 ints with uniform random distribution in range [1, 100]
        a = self.gen_random(100)
        self.assertLessEqual(find_duplicates(a), len(a))

        # we should have more duplicates than the max(a) if range of ints is [1, 100]
        a = self.gen_random(1000)
        self.assertGreaterEqual(find_duplicates(a), max(a))

        a = self.gen_random(1000000)
        self.assertTrue(find_duplicates(a) > 0)


if __name__ == "__main__":
    unittest.main()

import unittest
import bisect
import random


class BisectTest(unittest.TestCase):

    def test_bisect_right(self):
        breakpoints = [60, 70, 80, 90]
        grades = 'FDCBA'

        def grade(score):
            i = bisect.bisect(breakpoints, score)
            return grades[i]

        actual_grades = [grade(score) for score in [55, 60, 65, 70, 75, 80, 85, 90, 95]]
        expected_grades = ['F', 'D', 'D', 'C', 'C', 'B', 'B', 'A', 'A']
        self.assertEqual(actual_grades, expected_grades)

    def test_bisect_insort(self):
        SIZE = 7
        random.seed(1729)

        expected_numbers = [0, 2, 6, 7, 8, 10, 10]
        actual_numbers = []
        for i in range(SIZE):
            new_item = random.randrange(SIZE * 2)
            bisect.insort(actual_numbers, new_item)
        self.assertEqual(expected_numbers, actual_numbers)


if __name__ == '__main__':
    unittest.main()

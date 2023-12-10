#
# [Sedgewick][Ch1][Python] Exercise 1.4.19 Local minimum of a matrix. Linearithmic time.
#
# $ python3 ex-1.4.19-local-minimum-matrix.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


def find_local_minimum_matrix(matrix: list[list[int]]) -> (int, int):
    def find_column_min(col):
        min_row = 0
        for row in range(1, len(matrix)):
            if matrix[row][col] < matrix[min_row][col]:
                min_row = row
        return min_row, col

    def binary_search(left: int, right: int):
        if left == right:
            min_row, _ = find_column_min(left)
            return min_row, left

        mid_col = left + (right - left) // 2
        min_row, _ = find_column_min(mid_col)

        # is mid column less than the left column
        is_mid_less_left_col = (mid_col == 0) or (
            matrix[min_row][mid_col] < matrix[min_row][mid_col - 1]
        )
        is_mid_less_right_col = (mid_col == len(matrix[min_row]) - 1) or (
            matrix[min_row][mid_col] < matrix[min_row][mid_col + 1]
        )
        if is_mid_less_left_col and is_mid_less_right_col:
            return min_row, mid_col

        # search in left side
        if mid_col > 0 and matrix[min_row][mid_col - 1] < matrix[min_row][mid_col]:
            return binary_search(left, mid_col - 1)
        # search in right side
        else:
            return binary_search(mid_col + 1, right)

    return binary_search(0, len(matrix[0]) - 1)


class FindLocalMinimumMatrixTest(unittest.TestCase):
    def test_find_local_minimum_matrix(self):
        test_cases = [
            ([[1, 2], [3, 4]], (0, 0)),
            ([[1, 1, 1], [1, 0, 1], [1, 1, 1]], (1, 1)),
            ([[10, 20, 15], [21, 30, 14], [7, 16, 32]], (2, 0)),
        ]
        for matrix, expected in test_cases:
            self.assertEqual(find_local_minimum_matrix(matrix), expected)


if __name__ == "__main__":
    unittest.main()

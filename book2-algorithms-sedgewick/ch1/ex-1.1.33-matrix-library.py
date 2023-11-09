import unittest


class Matrix:
    @staticmethod
    def dot(a: list[list[float]], b: list[list[float]]) -> float:
        if len(a) != len(b):
            raise ValueError("a length should be equal to b")
        return sum([a[i] * b[i] for i in range(len(a))])

    @staticmethod
    def mult(a: list[list[float]], b: list[list[float]]) -> list[list[float]]:
        a_rows = len(a)
        a_cols = len(a[0])
        b_rows = len(b)
        b_cols = len(b[0])

        if a_cols != b_rows:
            raise ValueError(
                "Number of columns in A must be equal to the number of rows in B"
            )
        res = [[0 for _ in range(b_cols)] for row in range(a_rows)]

        # Matrix multiplication
        for i in range(a_rows):
            for j in range(b_cols):
                for k in range(a_cols):
                    res[i][j] += a[i][k] * b[k][j]
        return res

    @staticmethod
    def transpose(a: list[list[float]]) -> list[list[float]]:
        for i in range(len(a)):
            for j in range(i):
                a[i][j], a[j][i] = a[j][i], a[i][j]
        return a


class TestMatrix(unittest.TestCase):
    def test_dot(self):
        self.assertEqual(Matrix.dot([], []), 0)
        self.assertEqual(Matrix.dot([1], [1]), 1)
        self.assertEqual(Matrix.dot([1, 1, 1], [1, 1, 1]), 3)
        self.assertEqual(Matrix.dot([1, 2, 3], [1, 2, 3]), 14)

    def test_mult(self):
        with self.assertRaises(ValueError):
            Matrix.mult([[]], [[]])
        self.assertEqual(Matrix.mult([[1]], [[1]]), [[1]])
        self.assertEqual(Matrix.mult([[1, 2]], [[1], [2]]), [[5]])
        self.assertEqual(
            Matrix.mult([[1, 2], [3, 4]], [[1, 2], [3, 4]]), [[7, 10], [15, 22]]
        )

    def test_transpose(self):
        self.assertEqual(Matrix.transpose([[]]), [[]])
        self.assertEqual(Matrix.transpose([[1]]), [[1]])
        self.assertEqual(
            Matrix.transpose([[1, 2, 3], [4, 5, 6], [7, 8, 9]]),
            [[1, 4, 7], [2, 5, 8], [3, 6, 9]],
        )


if __name__ == "__main__":
    unittest.main()

import math
import unittest


def square_root(n: float) -> float:
    if n < 0:
        return math.nan
    eps = 1e-15
    t = n
    while abs(t - n / t) > eps * t:
        t = (n / t + t) / 2.0
    return t


class TestSquareRoot(unittest.TestCase):
    def test_square_root(self):
        self.assertIs(square_root(-1), math.nan)
        self.assertAlmostEqual(square_root(4), 2)
        self.assertAlmostEqual(square_root(81), 9)
        self.assertAlmostEqual(square_root(100), 10)
        self.assertAlmostEqual(square_root(42), 6.48074069840786)


if __name__ == "__main__":
    unittest.main()

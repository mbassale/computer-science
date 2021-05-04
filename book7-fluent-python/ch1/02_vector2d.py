import math
import unittest


class Vector:

    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return f'Vector({self.x!r}, {self.y!r})'

    def __abs__(self):
        return math.hypot(self.x, self.y)

    def __bool__(self):
        return bool(abs(self))

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Vector(x, y)

    def __sub__(self, other):
        x = self.x - other.x
        y = self.y - other.y
        return Vector(x, y)

    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)

    def __truediv__(self, scalar):
        return Vector(self.x / scalar, self.y / scalar)


class TestVector(unittest.TestCase):

    def assertVector(self, v, x, y, delta_places=3):
        self.assertIsNotNone(v)
        self.assertIsInstance(v, Vector)
        self.assertAlmostEqual(x, v.x, delta_places)
        self.assertAlmostEqual(y, v.y, delta_places)

    def test_repr(self):
        v = Vector(2, 4)
        self.assertEqual('Vector(2, 4)', f'{v!r}')

    def test_add(self):
        v1 = Vector(2, 4)
        v2 = Vector(2, 1)
        res = v1 + v2
        self.assertVector(res, 4, 5)

    def test_sub(self):
        v1 = Vector(2, 4)
        v2 = Vector(2, 1)
        res = v1 - v2
        self.assertVector(res, 0, 3)

    def test_abs(self):
        v = Vector(3, 4)
        self.assertEqual(5, abs(v))

    def test_bool(self):
        v = Vector(0, 0)
        self.assertFalse(v)

        v = Vector(3, 4)
        self.assertTrue(v)

    def test_mul(self):
        v1 = Vector(3, 4)
        res = v1 * 3
        self.assertVector(res, 9, 12)
        self.assertEqual(15, abs(res))

    def test_div(self):
        v1 = Vector(4, 4)
        res = v1 / 4
        self.assertVector(res, 1, 1)


if __name__ == '__main__':
    unittest.main()

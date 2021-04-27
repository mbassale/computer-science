import unittest


def gcd(p, q):
    if q == 0:
        return p
    r = p % q
    return gcd(q, r)


class GCDTest(unittest.TestCase):

    def test_zero(self):
        self.assertEqual(gcd(0, 0), 0)
        self.assertEqual(gcd(10, 0), 10)
        self.assertEqual(gcd(-10, 0), -10)

    def test_gcd(self):
        self.assertEqual(gcd(6, 3), 3)
        self.assertEqual(gcd(64, 8), 8)
        self.assertEqual(gcd(81, 7), 1)
        self.assertEqual(gcd(-81, 7), 1)


if __name__ == '__main__':
    unittest.main()

import unittest


def gcd(p, q):
    if q == 0:
        return pcd
    r = p % q
    return gcd(q, r)


class GCDTest(unittest.TestCase):

    def test_zero():
        self.assertEqual(gcd(0, 0), 0)
        self.assertEqual(gcd(10, 0), 10)


if __name__ == '__main__':
    unittest.main()

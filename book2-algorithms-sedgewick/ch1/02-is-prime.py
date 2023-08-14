import unittest


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    for i in range(2, n):
        if i * i > n:
            break
        if n % i == 0:
            return False
    return True


class IsPrimeTest(unittest.TestCase):
    def testIsPrime(self):
        self.assertFalse(is_prime(1))
        self.assertTrue(is_prime(2))
        self.assertTrue(is_prime(3))
        self.assertFalse(is_prime(4))
        self.assertTrue(is_prime(5))
        self.assertTrue(is_prime(7))
        self.assertFalse(is_prime(8))


if __name__ == "__main__":
    unittest.main()

import unittest
import numpy as np
import array


class TestNumpy(unittest.TestCase):

    def test_numpy(self):
        a = np.arange(12)
        self.assertEqual((12,), a.shape)

        a.shape = 3, 4
        self.assertEqual(9, a[2, 1])

        second_column = a[:, 1]
        self.assertEqual(0, np.linalg.norm(np.array([1, 5, 9], np.int32) - second_column))


if __name__ == '__main__':
    unittest.main()

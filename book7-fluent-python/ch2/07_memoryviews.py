import unittest
from array import array


class TestMemoryView(unittest.TestCase):

    def test_memory_view(self):
        octets = array('B', range(6))
        m1 = memoryview(octets)
        l1 = m1.tolist()
        self.assertEqual([0, 1, 2, 3, 4, 5], l1)

        m2 = m1.cast('B', [2, 3])
        l2 = m2.tolist()
        self.assertEqual([[0, 1, 2], [3, 4, 5]], l2)

        m3 = m1.cast('B', [3, 2])
        l3 = m3.tolist()
        self.assertEqual([[0, 1], [2, 3], [4, 5]], l3)

        m2[1, 1] = 22
        m3[1, 1] = 33
        self.assertEqual([0, 1, 2, 33, 22, 5], octets.tolist())


if __name__ == '__main__':
    unittest.main()

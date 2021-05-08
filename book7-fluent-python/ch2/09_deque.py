from collections import deque
import unittest


class TestDeque(unittest.TestCase):

    def test_deque(self):
        dq = deque(range(10), maxlen=10)
        self.assertEqual([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], list(dq))

        dq.rotate(3)
        self.assertEqual([7, 8, 9, 0, 1, 2, 3, 4, 5, 6], list(dq))

        dq.rotate(-4)
        self.assertEqual([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], list(dq))

        dq.appendleft(-1)
        self.assertEqual([-1, 1, 2, 3, 4, 5, 6, 7, 8, 9], list(dq))

        dq.extend([11, 22, 33])
        self.assertEqual([3, 4, 5, 6, 7, 8, 9, 11, 22, 33], list(dq))

        dq.extendleft([10, 20, 30, 40])
        self.assertEqual([40, 30, 20, 10, 3, 4, 5, 6, 7, 8], list(dq))


if __name__ == '__main__':
    unittest.main()

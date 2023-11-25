#
# [Sedgewick][Ch1][Python] Exercise 1.3.6 Reverse a Queue by using a Stack
#
# $ python ex-1.3.6-reverse-queue-with-stack.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest
from queue import Queue


def reverse_queue(q: Queue) -> Queue:
    stack = []
    while not q.empty():
        stack.append(q.get())
    while len(stack) > 0:
        q.put(stack.pop())
    return q


class ReverseQueueTest(unittest.TestCase):
    def test_reverse(self):
        items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        q = Queue()
        for n in items:
            q.put(n)
        q = reverse_queue(q)
        items_reversed = []
        while not q.empty():
            items_reversed.append(q.get())
        self.assertEqual(items, list(reversed(items_reversed)))


if __name__ == "__main__":
    unittest.main()

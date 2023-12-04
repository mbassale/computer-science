#
# [Sedgewick][Ch1][Python] Exercise 1.3.49 Queue with constant number of stacks.
#
# $ python ex-1.3.49-queue-with-two-stacks.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s

# OK
#
import unittest
import random


class QueueWithTwoStacks:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def enqueue(self, value) -> None:
        self.stack1.append(value)

    def dequeue(self):
        while len(self.stack1) > 0:
            self.stack2.append(self.stack1.pop())
        return self.stack2.pop()

    def peek(self):
        while len(self.stack1) > 0:
            self.stack2.append(self.stack1.pop())
        return self.stack2[-1]

    def __len__(self):
        return len(self.stack1) + len(self.stack2)

    def empty(self):
        return len(self) == 0


class QueueWithTwoStacksTest(unittest.TestCase):
    def test_queue_with_two_stacks(self):
        data1 = [random.randint(1, 100) for _ in range(100)]
        q = QueueWithTwoStacks()
        for value in data1:
            q.enqueue(value)
        data2 = []
        while not q.empty():
            data2.append(q.dequeue())
        self.assertEqual(data1, data2)


if __name__ == "__main__":
    unittest.main()

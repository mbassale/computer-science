#
# [Sedgewick][Ch1][Python] Exercise 1.3.29 Queue with Circular Linked List
#
# $ python ex-1.3.29-queue-circular-linked-list.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest


class Node:
    def __init__(self, value, next: "Node" = None):
        self.value = value
        self.next = next


class Queue:
    def __init__(self):
        self.last = None
        self.n = 0

    def enqueue(self, value):
        new_node = Node(value)
        if self.n == 1:
            new_node.next = self.last
            self.last.next = new_node
        elif self.n > 1:
            first = self.last.next
            self.last.next = new_node
            new_node.next = first
        self.last = new_node
        self.n += 1

    def dequeue(self):
        if self.last is None:
            raise ValueError("Attempting to dequeue from an empty queue")

        value = None
        # is there a first node?
        old_first = self.last.next
        if old_first:
            value = old_first.value
            self.last.next = old_first.next
        else:  # we have only one node
            value = self.last.value
            self.last = None

        self.n -= 1
        return value

    def size(self):
        return self.n

    def empty(self):
        return self.size() == 0

    def __str__(self) -> str:
        tmp = self.last.next
        values = []
        while tmp and tmp != self.last:
            values.append(str(tmp.value))
            tmp = tmp.next
        if self.last != None:
            values.append(str(self.last.value))
        return "[" + ",".join(values) + "]"


class CircularQueueTest(unittest.TestCase):
    def test_circular_queue(self):
        values = [i + 1 for i in range(20)]
        q = Queue()
        self.assertTrue(q.empty())
        self.assertEqual(q.size(), 0)
        for n in values:
            q.enqueue(n)
        self.assertFalse(q.empty())
        self.assertEqual(q.size(), 20)
        actual_values = []
        while not q.empty():
            actual_values.append(q.dequeue())
        self.assertTrue(q.empty())
        self.assertEqual(q.size(), 0)
        self.assertEqual(values, actual_values)


if __name__ == "__main__":
    unittest.main()

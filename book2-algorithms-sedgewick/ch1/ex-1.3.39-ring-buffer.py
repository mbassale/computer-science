#
# [Sedgewick][Ch1][Python] Exercise 1.3.39 Ring Buffer implementation with circular queue.
#
# $ python ex-1.3.39-ring-buffer.py
# ..
# ----------------------------------------------------------------------
# Ran 2 tests in 0.000s
#
# OK
#
import unittest


class RingBufferFullException(Exception):
    pass


class RingBufferEmptyException(Exception):
    pass


class RingBuffer:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.buffer = [None for _ in range(capacity)]
        self.front = self.rear = -1

    def is_full(self) -> bool:
        return (self.rear + 1) % self.capacity == self.front

    def is_empty(self) -> bool:
        return self.front == -1

    def enqueue(self, item):
        if self.is_full():
            raise RingBufferFullException("RingBuffer is full")
        if self.is_empty():
            self.front = 0
        self.rear = (self.rear + 1) % self.capacity
        self.buffer[self.rear] = item

    def dequeue(self):
        if self.is_empty():
            raise RingBufferEmptyException("RingBuffer is empty")
        item = self.buffer[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.capacity
        return item


class RingBufferTest(unittest.TestCase):
    def test_ringbuffer(self):
        buffer = RingBuffer(5)
        [buffer.enqueue(i + 1) for i in range(3)]
        self.assertEqual([buffer.dequeue() for _ in range(3)], [1, 2, 3])

    def test_exceptions(self):
        # test ring buffer full
        buffer = RingBuffer(5)
        with self.assertRaises(RingBufferFullException):
            [buffer.enqueue(i + 1) for i in range(10)]

        self.assertEqual([buffer.dequeue() for _ in range(5)], [1, 2, 3, 4, 5])

        # test ring buffer empty
        with self.assertRaises(RingBufferEmptyException):
            [buffer.dequeue() for _ in range(10)]


if __name__ == "__main__":
    unittest.main()

#
# [Sedgewick][Ch1][Python] Algorithm 1.3 FIFO queue
#
# $ python 15_linked_list_queue.py 20
# Enqueue: 260 Size: 1
# Dequeue: 260 Size: 0
# Enqueue: 312 Size: 1
# Dequeue: 312 Size: 0
# Enqueue: 213 Size: 1
# Enqueue: 660 Size: 2
# Enqueue: 175 Size: 3
# Enqueue: 662 Size: 4
# Enqueue: 685 Size: 5
# Enqueue: 309 Size: 6
# Dequeue: 213 Size: 5
# Enqueue: 755 Size: 6
# Enqueue: 762 Size: 7
# Enqueue: 289 Size: 8
# Enqueue: 966 Size: 9
# Enqueue: 10 Size: 10
# Enqueue: 543 Size: 11
# Enqueue: 849 Size: 12
# Dequeue: 660 Size: 11
# Enqueue: 628 Size: 12
# Enqueue: 43 Size: 13
# Enqueue: 913 Size: 14
# Enqueue: 836 Size: 15
# Enqueue: 80 Size: 16
# Dequeue: 175 Size: 15
# Dequeue: 662 Size: 14
# Dequeue: 685 Size: 13
# Dequeue: 309 Size: 12
# Dequeue: 755 Size: 11
# Dequeue: 762 Size: 10
# Dequeue: 289 Size: 9
# Dequeue: 966 Size: 8
# Dequeue: 10 Size: 7
# Dequeue: 543 Size: 6
# Dequeue: 849 Size: 5
# Dequeue: 628 Size: 4
# Dequeue: 43 Size: 3
# Dequeue: 913 Size: 2
# Dequeue: 836 Size: 1
# Dequeue: 80 Size: 0
#
import sys
import random


class Node:
    def __init__(self, value, next: "Node" = None):
        self.value = value
        self.next = next


class Queue:
    def __init__(self):
        self.first: Node = None
        self.last: Node = None
        self.n: int = 0

    def empty(self) -> int:
        return self.n == 0

    def size(self) -> int:
        return self.n

    def enqueue(self, item) -> None:
        old_last = self.last
        self.last = Node(item)
        if self.empty():
            self.first = self.last
        else:
            old_last.next = self.last
        self.n += 1

    def dequeue(self):
        item = self.first
        self.first = self.first.next
        self.n -= 1
        if self.empty():
            self.last = None
        return item.value


def run(number_values: int) -> None:
    values = [random.randint(1, 1000) for _ in range(number_values)]
    queue = Queue()
    for value in values:
        queue.enqueue(value)
        print(f"Enqueue: {value} Size: {queue.size()}")
        if not queue.empty() and random.random() < 0.25:
            item = queue.dequeue()
            print(f"Dequeue: {item} Size: {queue.size()}")
    while not queue.empty():
        item = queue.dequeue()
        print(f"Dequeue: {item} Size: {queue.size()}")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments.")
    run(int(sys.argv[1]))

#
# [Sedgewick][Ch1][Python] Algorithm 1.2 Pushdown stack (linked-list implementation)
#
# $ python 14_linked_list_stack.py 20
# Pushing: 115 Size: 1
# Popping: 115 Size: 0
# Pushing: 856 Size: 1
# Pushing: 79 Size: 2
# Pushing: 979 Size: 3
# Pushing: 226 Size: 4
# Pushing: 885 Size: 5
# Pushing: 836 Size: 6
# Pushing: 402 Size: 7
# Popping: 402 Size: 6
# Pushing: 649 Size: 7
# Popping: 649 Size: 6
# Pushing: 713 Size: 7
# Pushing: 285 Size: 8
# Pushing: 893 Size: 9
# Popping: 893 Size: 8
# Pushing: 707 Size: 9
# Pushing: 334 Size: 10
# Popping: 334 Size: 9
# Pushing: 346 Size: 10
# Popping: 346 Size: 9
# Pushing: 823 Size: 10
# Pushing: 501 Size: 11
# Popping: 501 Size: 10
# Pushing: 545 Size: 11
# Pushing: 534 Size: 12
# Pushing: 168 Size: 13
# Popping: 168 Size: 12
# Popping: 534 Size: 11
# Popping: 545 Size: 10
# Popping: 823 Size: 9
# Popping: 707 Size: 8
# Popping: 285 Size: 7
# Popping: 713 Size: 6
# Popping: 836 Size: 5
# Popping: 885 Size: 4
# Popping: 226 Size: 3
# Popping: 979 Size: 2
# Popping: 79 Size: 1
# Popping: 856 Size: 0
#
import sys
import random


class Node:
    def __init__(self, value, next: "Node" = None):
        self.value = value
        self.next = next


class Stack:
    def __init__(self):
        self.first: Node = None
        self.n: int = 0

    def empty(self) -> int:
        return self.n == 0

    def size(self) -> int:
        return self.n

    def push(self, item) -> None:
        old_first = self.first
        self.first = Node(item, old_first)
        self.n += 1

    def pop(self):
        item = self.first
        self.first = self.first.next
        self.n -= 1
        return item.value


def run(number_values: int) -> None:
    values = [random.randint(1, 1000) for _ in range(number_values)]
    stack = Stack()
    for value in values:
        stack.push(value)
        print(f"Pushing: {value} Size: {stack.size()}")
        if not stack.empty() and random.random() < 0.25:
            item = stack.pop()
            print(f"Popping: {item} Size: {stack.size()}")
    while not stack.empty():
        item = stack.pop()
        print(f"Popping: {item} Size: {stack.size()}")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments.")
    run(int(sys.argv[1]))

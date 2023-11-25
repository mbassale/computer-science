#
# [Sedgewick][Ch1][Python] Algorithm 1.1 Pushdown (LIFO) stack (resizing array implementation)
#
# $ python3 13_dynamic_capacity_stack.py 20
# Pushing: 325 Size: 1 Capacity: 10
# Popping: 325 Size: 0 Capacity: 10
# Pushing: 986 Size: 1 Capacity: 10
# Popping: 986 Size: 0 Capacity: 10
# Pushing: 932 Size: 1 Capacity: 10
# Pushing: 343 Size: 2 Capacity: 10
# Pushing: 728 Size: 3 Capacity: 10
# Pushing: 62 Size: 4 Capacity: 10
# Pushing: 26 Size: 5 Capacity: 10
# Popping: 26 Size: 4 Capacity: 10
# Pushing: 692 Size: 5 Capacity: 10
# Pushing: 806 Size: 6 Capacity: 10
# Pushing: 803 Size: 7 Capacity: 10
# Pushing: 425 Size: 8 Capacity: 10
# Pushing: 149 Size: 9 Capacity: 10
# Pushing: 591 Size: 10 Capacity: 10
# Pushing: 965 Size: 11 Capacity: 20
# Pushing: 869 Size: 12 Capacity: 20
# Pushing: 650 Size: 13 Capacity: 20
# Pushing: 994 Size: 14 Capacity: 20
# Pushing: 997 Size: 15 Capacity: 20
# Pushing: 181 Size: 16 Capacity: 20
# Pushing: 388 Size: 17 Capacity: 20
# Popping: 388 Size: 16 Capacity: 20
# Popping: 181 Size: 15 Capacity: 20
# Popping: 997 Size: 14 Capacity: 20
# Popping: 994 Size: 13 Capacity: 20
# Popping: 650 Size: 12 Capacity: 20
# Popping: 869 Size: 11 Capacity: 20
# Popping: 965 Size: 10 Capacity: 20
# Popping: 591 Size: 9 Capacity: 20
# Popping: 149 Size: 8 Capacity: 20
# Popping: 425 Size: 7 Capacity: 20
# Popping: 803 Size: 6 Capacity: 20
# Popping: 806 Size: 5 Capacity: 10
# Popping: 692 Size: 4 Capacity: 10
# Popping: 62 Size: 3 Capacity: 10
# Popping: 728 Size: 2 Capacity: 5
# Popping: 343 Size: 1 Capacity: 2
# Popping: 932 Size: 0 Capacity: 1
#
import sys
import random

DEFAULT_INITIAL_CAPACITY: int = 10


class DynamicCapacityStack:
    def __init__(self, capacity=DEFAULT_INITIAL_CAPACITY):
        self.data = [None for _ in range(capacity)]
        self.n = 0

    def empty(self) -> bool:
        return self.n == 0

    def size(self) -> int:
        return self.n

    def capacity(self) -> int:
        return len(self.data)

    def resize(self, new_capacity: int) -> None:
        tmp = [None for _ in range(new_capacity)]
        for i in range(self.n):
            tmp[i] = self.data[i]
        self.data = tmp

    def push(self, item) -> None:
        if self.n == len(self.data):
            self.resize(2 * len(self.data))
        self.data[self.n] = item
        self.n += 1

    def pop(self):
        self.n -= 1
        item = self.data[self.n]
        self.data[self.n] = None  # Avoid loitering
        if self.n == len(self.data) // 4:
            self.resize(len(self.data) // 2)
        return item


def run(number_values: int):
    values = [random.randint(1, 1000) for _ in range(number_values)]
    dyn_stack = DynamicCapacityStack()
    for value in values:
        dyn_stack.push(value)
        print(
            f"Pushing: {value} Size: {dyn_stack.size()} Capacity: {dyn_stack.capacity()}"
        )
        if not dyn_stack.empty() and random.random() < 0.10:
            item = dyn_stack.pop()
            print(
                f"Popping: {item} Size: {dyn_stack.size()} Capacity: {dyn_stack.capacity()}"
            )
    while not dyn_stack.empty():
        item = dyn_stack.pop()
        print(
            f"Popping: {item} Size: {dyn_stack.size()} Capacity: {dyn_stack.capacity()}"
        )


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments.")
    run(int(sys.argv[1]))

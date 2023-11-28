#
# [Sedgewick][Ch1][Python] Exercise 1.3.37 Josephus Problem with circular linked list.
#
# $ python ex-1.3.37-josephus-problem.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s

# OK
#
import unittest


class Node:
    def __init__(self, value, next: "Node" = None):
        self.value = value
        self.next = next


def list2str(head: Node) -> str:
    values = [str(head.value)]
    tmp = head.next
    while tmp != head:
        values.append(str(tmp.value))
        tmp = tmp.next
    return "[" + ",".join(values) + "]"


def make_circular_list(n: int):
    values = [i + 1 for i in range(n + 1)]
    head = Node(values[0])
    prev = head
    for value in range(2, len(values)):
        node = Node(value)
        prev.next = node
        prev = node
    prev.next = head  # make a circular list
    return head


def solve_josephus(n: int, m: int) -> list[int]:
    head = make_circular_list(n)
    prev = None
    curr = head
    removed = []
    while curr.next != curr:
        count = 1
        while count < m:
            prev = curr
            curr = curr.next
            count += 1
        # remove the m-th node
        removed.append(curr.value)
        prev.next = curr.next
        curr = curr.next
    removed.append(curr.value)
    return removed


class JosephusProblemTest(unittest.TestCase):
    def test_solution(self):
        removed = solve_josephus(3, 3)
        self.assertEqual(removed, [3, 1, 2])
        removed = solve_josephus(10, 2)
        self.assertEqual(removed, [2, 4, 6, 8, 10, 3, 7, 1, 9, 5])


if __name__ == "__main__":
    unittest.main()

#
# [Sedgewick][Ch1][Python] Exercise 1.3.30 Reverse Linked List (Iterative and Recursive solutions)
#
# $ python ex-1.3.30-reverse-linked-list.py
# ...
# ----------------------------------------------------------------------
# Ran 3 tests in 0.000s
#
# OK
#
import unittest


class Node:
    def __init__(self, value, next: "Node" = None) -> None:
        self.value = value
        self.next = next


class List:
    def __init__(self):
        self.last = None
        self.n = 0

    def size(self) -> int:
        return self.n

    def empty(self) -> bool:
        return self.n == 0

    def append(self, value):
        new_node = Node(value)
        if self.n == 0:
            self.last = new_node
        elif self.n == 1:
            first = self.last
            first.next = new_node
            new_node.next = first
            self.last = new_node
        else:
            first = self.last.next
            self.last.next = new_node
            new_node.next = first
            self.last = new_node
        self.n += 1

    def reverse(self) -> None:
        if self.n > 1:
            old_first = self.last.next
            first = self.last.next
            reversed = self.last
            count = self.n
            while count > 0:
                second = first.next
                first.next = reversed
                reversed = first
                first = second
                count -= 1
            self.last = old_first

    def reverse_recursive(self) -> None:
        if self.n <= 1:
            return
        old_first = self.last.next
        self.reverse_recursive_impl(self.n, self.last.next)
        self.last = old_first

    def reverse_recursive_impl(self, count: int, first: Node) -> Node:
        if count == 0:
            return first
        second = first.next
        rest = self.reverse_recursive_impl(count - 1, second)
        second.next = first
        return rest

    def __str__(self) -> str:
        if self.n == 0:
            return "[]"
        elif self.n == 1:
            return f"[{self.last.value}]"
        elif self.n > 1:
            values = []
            tmp = self.last.next
            while tmp and tmp != self.last:
                values.append(str(tmp.value))
                tmp = tmp.next
            values.append(str(self.last.value))
            return "[" + ", ".join(values) + "]"


class ReverseLinkedListTest(unittest.TestCase):
    def test_empty(self):
        lst = List()
        self.assertTrue(lst.empty())
        self.assertTrue(lst.size() == 0)
        lst.reverse()
        self.assertTrue(lst.empty())
        self.assertTrue(lst.size() == 0)
        self.assertEqual("[]", str(lst))

    def test_non_empty_reverse(self):
        test_cases = [
            [1],
            [1, 2],
            [1, 2, 3],
            [i + 1 for i in range(20)],
        ]
        for values in test_cases:
            lst = List()
            for n in values:
                lst.append(n)
            self.assertFalse(lst.empty())
            self.assertTrue(lst.size() > 0)
            self.assertEqual(str(lst), str(values))

            lst.reverse()
            self.assertEqual(lst.size(), len(values))
            self.assertEqual(str(lst), str(list(reversed(values))))

    def test_recursive_reverse(self):
        test_cases = [
            [1],
            [1, 2],
            [1, 2, 3],
            [i + 1 for i in range(20)],
        ]
        for values in test_cases:
            lst = List()
            for n in values:
                lst.append(n)
            self.assertFalse(lst.empty())
            self.assertTrue(lst.size() > 0)
            self.assertEqual(str(lst), str(values))

            lst.reverse_recursive()
            self.assertEqual(lst.size(), len(values))
            self.assertEqual(str(lst), str(list(reversed(values))))


if __name__ == "__main__":
    unittest.main()

#
# [Sedgewick][Ch1][Python] Exercise 1.3.45 Stack Generability
#
# $ python3 ex-1.3.45-stack-generability.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s

# OK
#
import unittest


def check_stack_generability(operations: list[int]) -> bool:
    """
    Using top-pointer technique, by reusing the input array we check if the stack
    is valid by checking the pointer to the top of the stack and the top itself.
    """
    top = -1
    for op in operations:
        if op > 0:
            top += 1
            operations[top] = op
        elif op < 0:
            if top == -1 or operations[top] != -op:
                return False
            top -= 1
    return True


class StackGenerabilityTest(unittest.TestCase):
    def test_stack_generability(self):
        test_cases = [
            ([1, 2, -2, -1], True),
            ([1, -1], True),
            ([1, -2], False),
            ([1, 2, -1, -2], False),
            ([1, -1, 1, -1, 1, 1, -1, -1], True),
            ([1, -1, 1, -1, 1, 1, -1, -1, -1], False),
        ]
        for test_case in test_cases:
            ops, expected = test_case
            self.assertEqual(
                check_stack_generability(ops), expected, f"Failed: {test_case}"
            )


if __name__ == "__main__":
    unittest.main()

#
# [Sedgewick][Ch1][Python] Exercise 1.3.4 Parentheses Checker
#
# $ python 17_stack_parentheses.py
# ..
# ----------------------------------------------------------------------
# Ran 2 tests in 0.000s

# OK
#
import unittest


def is_left_parentheses(c: str) -> bool:
    if c == "(" or c == "[" or c == "{":
        return True
    return False


def is_right_parentheses(c: str) -> bool:
    if c == ")" or c == "]" or c == "}":
        return True
    return False


def is_left_matching_right(left: str, right: str) -> bool:
    if left == "(" and right == ")":
        return True
    elif left == "[" and right == "]":
        return True
    elif left == "{" and right == "}":
        return True
    return False


def check_parentheses(s: str) -> bool:
    stack = []
    for ch in s:
        if is_left_parentheses(ch):
            stack.append(ch)
        elif is_right_parentheses(ch):
            if len(stack) == 0:
                return False
            left = stack.pop()
            if not is_left_matching_right(left, ch):
                return False
    return len(stack) == 0


class TestCheckParentheses(unittest.TestCase):
    def test_balanced(self):
        test_cases = ["()", "[]", "{}", "[()]{}{[()()]()}"]
        for test_case in test_cases:
            self.assertTrue(check_parentheses(test_case), f"test_case: {test_case}")

    def test_unbalanced(self):
        test_cases = ["(", "[", "{", ")", "]", "}", "(]", "[}", ")}", "[()]}{[()()]()}"]
        for test_case in test_cases:
            self.assertFalse(check_parentheses(test_case), f"test_case: {test_case}")


if __name__ == "__main__":
    unittest.main()

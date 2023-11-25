#
# [Sedgewick][Ch1][Python] Exercise 1.3.9 Infix Completion
#
# $ python 18_infix_completion.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
import unittest
from queue import Queue


def is_left_parentheses(ch: str) -> bool:
    if ch == "(" or ch == "[" or ch == "{":
        return True
    return False


def is_right_parentheses(ch: str) -> bool:
    if ch == ")" or ch == "]" or ch == "}":
        return True
    return False


def get_correction(ch: str) -> str:
    match ch:
        case ")":
            return "("
        case "]":
            return "["
        case "}":
            return "{"
        case _:
            raise ValueError(f"Invalid parentheses: {ch}")


def infix_completion(s: str) -> str:
    stack = []
    fixed_expr = ""
    for ch in s:
        if ch.isspace():
            continue
        elif is_right_parentheses(ch):
            if len(stack) == 0:
                fixed_expr = get_correction(ch) + fixed_expr
            else:
                stack.pop()
            fixed_expr += ch
        else:
            fixed_expr += ch
            if is_left_parentheses(ch):
                stack.append(ch)
    return fixed_expr


class InfixCompletionTest(unittest.TestCase):
    def test_infix_completion(self):
        test_cases = [
            (")", "()"),
            ("1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )", "(((((1+2)*3-4)*5-6)))"),
            ("( 1 + 2 * ( 3 - 4 ) )", "(1+2*(3-4))"),
        ]
        for test_case in test_cases:
            test = test_case[0]
            expected = test_case[1]
            self.assertEqual(infix_completion(test), expected)


if __name__ == "__main__":
    unittest.main()

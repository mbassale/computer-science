#
# [Sedgewick][Ch1][Python] Exercise 1.3.10 Infix to Postfix conversion
#
# $ python ex-1.3.10-infix-to-postfix.py
# .
# ----------------------------------------------------------------------
# Ran 1 test in 0.000s
#
# OK
#
# Example Trace:
# INPUT: ((A+B)*C)+(A+B)            EXPECTED: AB+C*AB++
# IN              STACK             POSTFIX_EXPR
# (               (
# (               (,(
# A                                 A
# +               (,(,+
# B                                 A,B
# )               (,                A,B,+
# *               (,*
# C                                 A,B,+,C
# )                                 A,B,+,C,*
# +               +
# (               +,(
# A                                 A,B,+,C,*,A
# +               +,(,+
# B                                 A,B,+,C,*,A,B
# )                                 A,B,+,C,*,A,B,+,+
import unittest


def is_operator(ch: str) -> bool:
    if ch == "+" or ch == "-" or ch == "*" or ch == "/":
        return True
    return False


def infix_to_postfix(infix_expr: str) -> str:
    precedences = {"+": 1, "-": 1, "*": 2, "/": 2}
    # holds operators and parentheses
    stack = []
    # holds the postfix expression
    postfix_expr = []
    for ch in infix_expr:
        if ch.isspace():
            continue
        if ch.isalnum():
            postfix_expr.append(ch)
        elif ch == "(":
            stack.append(ch)
        elif ch == ")":
            while len(stack) > 0 and stack[-1] != "(":
                postfix_expr.append(stack.pop())
            stack.pop()
        elif is_operator(ch):
            while (
                len(stack) > 0
                and stack[-1] != "("
                and precedences[stack[-1]] >= precedences[ch]
            ):
                postfix_expr.append(stack.pop())
            stack.append(ch)

    while len(stack) > 0:
        postfix_expr.append(stack.pop())

    return "".join(postfix_expr)


class InfixToPostfix(unittest.TestCase):
    def test_infix_to_postfix(self):
        test_cases = [
            ("((A+B)*C)", "AB+C*"),
            ("((A+B)*C)+(A+B)", "AB+C*AB++"),
            ("(A+(B*C))", "ABC*+"),
            ("A+B*C", "ABC*+"),
            ("A*B+C", "AB*C+"),
        ]
        for test_case in test_cases:
            infix_expr = test_case[0]
            expected_postfix_expr = test_case[1]
            actual_postfix_expr = infix_to_postfix(infix_expr)
            self.assertEqual(expected_postfix_expr, actual_postfix_expr)


if __name__ == "__main__":
    unittest.main()

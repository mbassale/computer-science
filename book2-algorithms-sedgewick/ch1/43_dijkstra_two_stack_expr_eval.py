#
# [Sedgewick][Ch1][Python] 1.3 Dijkstra Two-Stack Algorithm for Expression Evaluation
#
# $ python 43_dijkstra_two_stack_expr_eval.py "((1+2)*(5+3))"
# Evaluating: 2.0 + 1.0 = 3.0
# Evaluating: 3.0 + 5.0 = 8.0
# Evaluating: 8.0 * 3.0 = 24.0
# Result: 24.0
#
import sys


def is_operator(ch: str) -> bool:
    return ch == "+" or ch == "-" or ch == "*" or ch == "/"


def eval_binary(op: str, lhs_val: float, rhs_val: float):
    match op:
        case "+":
            return lhs_val + rhs_val
        case "-":
            return lhs_val - rhs_val
        case "*":
            return lhs_val * rhs_val
        case "/":
            if rhs_val != 0:
                return lhs_val / rhs_val
            else:
                raise ZeroDivisionError("division by zero")
        case _:
            raise ValueError(f"Unknown operator: {op}")


def run(input_expr: str):
    # operator stack
    ops = []
    # value stack
    vals = []
    for i in range(len(input_expr)):
        ch = input_expr[i]
        # ignore whitespace and left paren
        if ch.isspace() or ch == "(":
            continue
        elif is_operator(ch):
            ops.append(ch)
        elif ch == ")":
            op = ops.pop()
            lhs_val = vals.pop()
            rhs_val = vals.pop()
            res_val = eval_binary(op, lhs_val, rhs_val)
            print(f"Evaluating: {lhs_val} {op} {rhs_val} = {res_val}")
            vals.append(res_val)
        elif ch.isdigit():
            j = i
            while ch.isdigit() and j < len(input_expr):
                ch = input_expr[j]
                j += 1
            val = float(input_expr[i : (j - 1)])
            vals.append(val)
            i = j
    print(f"Result: {vals.pop()}")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments.")
    run(sys.argv[1])

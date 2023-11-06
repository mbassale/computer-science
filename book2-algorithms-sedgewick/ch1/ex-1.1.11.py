import sys
import random


def dump_bool(a: list[list]) -> str:
    """
    Returns a string representation of a two dimensional array (matrix) of boolean values.
    """
    s = ""
    for i in range(len(a)):
        for j in range(len(a[i])):
            s += ("*" if a[i][j] else " ") + " "
        s += "\n"
    return s


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing args")
        sys.exit(1)

    dim = int(sys.argv[1])
    a = [[random.randint(0, 1) for _ in range(0, dim)] for _ in range(0, dim)]
    print(dump_bool(a))

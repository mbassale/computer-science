import sys
import random


def print_matrix(a: list[list]) -> None:
    s = ""
    for i in range(0, len(a)):
        for j in range(0, len(a[i])):
            s += str(a[i][j]) + " "
        s += "\n"
    print(s)


def transpose(a: list[list]) -> list[list]:
    for i in range(0, len(a)):
        for j in range(0, i):
            a[i][j], a[j][i] = a[j][i], a[i][j]
    return a


def random_matrix(dim: int) -> list[list]:
    return [[random.randint(0, 10) for _ in range(0, dim)] for _ in range(0, dim)]


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments")
        sys.exit(1)
    dim = int(sys.argv[1])
    a = random_matrix(dim)
    print("Original:")
    print_matrix(a)
    print("Transpose:")
    print_matrix(transpose(a))

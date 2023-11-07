# Prints a matrix of 10 x 10 with 1 if element i, j are coprime, 0 otherwise
# Matrix:
#     1 2 3 4 5 6 7 8 9 10
# 1:  1 1 1 1 1 1 1 1 1 1
# 2:  1 0 1 0 1 0 1 0 1 0
# 3:  1 1 0 1 1 0 1 1 0 1
# 4:  1 0 1 0 1 0 1 0 1 0
# 5:  1 1 1 1 0 1 1 1 1 0
# 6:  1 0 0 0 1 0 1 0 0 0
# 7:  1 1 1 1 1 1 0 1 1 1
# 8:  1 0 1 0 1 0 1 0 1 0
# 9:  1 1 0 1 1 0 1 1 0 1
# 10: 1 0 1 0 0 0 1 0 1 0


def gcd(p: int, q: int) -> int:
    if q == 0:
        return p
    r = p % q
    return gcd(q, r)


def coprime(a: int, b: int) -> bool:
    return gcd(a, b) == 1


def print_matrix(m: list[list[int]]) -> None:
    s = "Matrix:\n"
    s += "    " + " ".join([str(i) for i in range(1, len(m[0]) + 1)]) + "\n"
    for row in range(0, len(m)):
        pad = ":  "
        if row == len(m) - 1:
            pad = ": "
        s += str(row + 1) + pad + " ".join(["1" if i else "0" for i in m[row]]) + "\n"
    print(s)


if __name__ == "__main__":
    m = [[False for _ in range(0, 10)] for _ in range(0, 10)]
    for i in range(1, 11):
        for j in range(1, 11):
            m[i - 1][j - 1] = coprime(i, j)
    print_matrix(m)

import sys


def mystery(a: int, b: int) -> int:
    if b == 0:
        return 0
    if b % 2 == 0:
        return mystery(a + a, b / 2)
    return mystery(a + a, b / 2) + a


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments")
        sys.exit(1)
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    print(f"a: {a}, b: {b}, mystery({a}, {b}): {mystery(a, b)}")

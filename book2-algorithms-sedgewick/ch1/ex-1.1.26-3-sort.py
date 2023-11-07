import sys
import random


def three_sort(a: int, b: int, c: int) -> tuple[int]:
    if a > b:
        a, b = b, a
    if a > c:
        a, c = c, a
    if b > c:
        b, c = c, b
    return (a, b, c)


if __name__ == "__main__":
    a, b, c = [random.randint(0, 100) for _ in range(3)]
    print(f"a={a}, b={b}, c={c}")
    a, b, c = three_sort(a, b, c)
    print(f"a={a}, b={b}, c={c}")

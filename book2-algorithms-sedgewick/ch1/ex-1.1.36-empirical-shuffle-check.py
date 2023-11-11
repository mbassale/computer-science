import sys
import random


def shuffle(a: list[float]) -> list[float]:
    for i in range(len(a)):
        r = random.randint(0, len(a) - 1)
        a[i], a[r] = a[r], a[i]
    return a


def shuffle_simulation(m: int, n: int) -> list[list[float]]:
    frequencies = [[0 for _ in range(m)] for _ in range(m)]
    for _ in range(n):
        a = [i for i in range(m)]
        b = shuffle(a)
        for i in range(len(b)):
            row = b[i]
            frequencies[row][i] += 1
    return frequencies


def dump_matrix(m: int, n: int, a: list[list[float]]) -> None:
    print(f"Target Frequency: m={m}, n={n}, prob={(n / m):.2f}")
    for row in a:
        print(" ".join([str(freq) for freq in row]))


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Missing arguments")
        sys.exit(1)
    m = int(sys.argv[1])
    n = int(sys.argv[2])
    frequencies = shuffle_simulation(m, n)
    dump_matrix(m, n, frequencies)

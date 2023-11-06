import sys
import random
from pprint import pformat


def histogram(a: list[int], m: int) -> list[int]:
    freqs = {}
    for i in a:
        if i in freqs:
            freqs[i] += 1
        else:
            freqs[i] = 1
    hist = [0 for _ in range(0, m)]
    for i in range(0, m):
        if i in freqs:
            hist[i] = freqs[i]
    return hist


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments")
        sys.exit(1)

    m = int(sys.argv[1])
    a = [random.randint(0, m) for _ in range(0, m)]
    print("a:", pformat(a), "m:", m)
    print("Histogram: ", pformat(histogram(a, m)))

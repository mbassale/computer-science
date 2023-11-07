import sys
import time


def binomial(n: int, k: int, p: float, memo={}) -> float:
    if n == 0 and k == 0:
        return 1.0
    if n < 0 or k < 0:
        return 0.0
    key = f"{n},{k},{p}"
    if key in memo:
        return memo[key]
    val = (1 - p) * binomial(n - 1, k, p, memo) + p * binomial(n - 1, k - 1, p, memo)
    memo[key] = val
    return val


if __name__ == "__main__":
    n = 100
    k = 50
    p = 0.25
    start = time.time_ns()
    b = binomial(n, k, p)
    end = time.time_ns()
    rtms = (end - start) / 1e6
    print(f"binomial({n}, {p}, {k}) = {b} rt: {rtms}ms")

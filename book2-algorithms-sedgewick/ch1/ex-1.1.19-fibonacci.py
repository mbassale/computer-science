import sys
import time


def fibonacci(n: int) -> int:
    """
    Fibonacci without memoization.
    """
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)


def fibonacciMemoization(n: int, memo={}) -> int:
    """
    Fibonacci with memoization as a dictionary.
    """
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n in memo:
        return memo[n]

    n1 = n - 1
    fib1 = 0
    if n1 in memo:
        fib1 = memo[n1]
    else:
        fib1 = fibonacciMemoization(n1, memo)
        memo[n1] = fib1

    n2 = n - 2
    fib2 = 0
    if n2 in memo:
        fib2 = memo[n2]
    else:
        fib2 = fibonacciMemoization(n2, memo)
        memo[n2] = fib2

    fib3 = fib1 + fib2
    memo[n] = fib3
    return fib3


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments")
        sys.exit(1)
    n = int(sys.argv[1])
    start = time.time_ns()
    fib1 = fibonacci(n)
    end = time.time_ns()
    rtms = (end - start) / 1e6
    print(f"fibonacci({n}): {fib1} rt: {rtms}ms")

    start = time.time_ns()
    fib2 = fibonacciMemoization(n)
    end = time.time_ns()
    rtms = (end - start) / 1e6
    print(f"fibonacciMemoization({n}): {fib2} rt: {rtms}ms")

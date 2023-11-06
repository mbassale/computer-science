import sys
import math

# For logarithms we have the following: ln(a * b) = ln(a) + ln(b)
# ln(n!) = ln(n * (n-1)!) = ln(n) + ln((n - 1)!)
# ln(n!) = ln(n) + ln(n - 1) + ln(n - 2) + ... + ln(1)


def ln_factorial(n: int) -> int:
    if n == 0 or n == 1:
        return 0
    else:
        return math.log(n) + ln_factorial(n - 1)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments")
        sys.exit(1)
    n = int(sys.argv[1])
    print(f"ln_factorial({n}): {ln_factorial(n)}")

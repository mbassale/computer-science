import sys


def int_not_larger_ln2(n: int) -> int:
    """
    Takes an int n as argument and returns the largest int not larger than the
    base-2 logarithm of n. Without using Math module.
    """
    k = 1
    i = 0
    while k <= n:
        k *= 2
        i += 1
    return i - 1


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments")
        sys.exit(1)
    n = int(sys.argv[1])
    print(f"IntNotLargerLn2({n}): {int_not_larger_ln2(n)}")

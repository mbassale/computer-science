import sys


def binary_str_repr(n: int) -> str:
    """
    Convert an integer to its binary representation and returns it as a str
    """
    s = ""
    while n > 0:
        s = str(int(n % 2)) + s
        n = int(n / 2)
    return s


if __name__ == "__main__":
    print("Missing required argument") if len(sys.argv) < 2 else None
    print(f"Bin: {binary_str_repr(int(sys.argv[1]))}")

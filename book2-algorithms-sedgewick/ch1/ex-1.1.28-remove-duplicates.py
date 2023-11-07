import random
from pprint import pformat


def binary_search(a: list[int], key: int, lo: int, hi: int) -> int:
    if lo > hi:
        return -1
    mid = int(lo + (hi - lo) / 2)
    if key == a[mid]:
        return mid
    if key < a[mid]:
        return binary_search(a, key, lo, mid - 1)
    else:
        return binary_search(a, key, mid + 1, hi)


def remove_duplicates(a: list[int]) -> list[int]:
    a = sorted(a)
    i = 0
    while i < len(a):
        key = a[i]
        idx = 0
        while idx >= 0:
            idx = binary_search(a, key, i + 1, len(a) - 1)
            if idx > 0:
                del a[idx]
        i += 1
    return a


if __name__ == "__main__":
    a = [random.randint(0, 10) for _ in range(30)]
    print(f"Original: {pformat(a)}")
    a = remove_duplicates(a)
    print(f"Duplicates Removed: {pformat(a)}")

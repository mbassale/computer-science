import sys
import random
from pprint import pformat


def trace_call(a: list[int], key: int, lo: int, hi: int, depth: int):
    indent = "".join([" " for _ in range(0, depth)])
    print(f"{indent}index_of({pformat(a)}, {key}, {lo}, {hi})")


def index_of(a: list[int], key: int, lo: int, hi: int, depth: int) -> int:
    trace_call(a, key, lo, hi, depth)
    if lo > hi:
        return -1
    mid = int(lo + (hi - lo) / 2)
    if key == a[mid]:
        return mid
    if key < a[mid]:
        return index_of(a, key, lo, mid - 1, depth + 1)
    else:
        return index_of(a, key, mid + 1, hi, depth + 1)


def binary_search(a: list[int], key: int) -> int:
    return index_of(a, key, 0, len(a) - 1, 0)


if __name__ == "__main__":
    a = sorted([random.randint(0, 100) for _ in range(20)])
    test_idx = random.randint(0, 19)
    key = a[test_idx]
    print(f"Looking: {key}")
    idx = binary_search(a, key)
    print(f"Found: {idx}, a[{idx}] = {a[idx]}")

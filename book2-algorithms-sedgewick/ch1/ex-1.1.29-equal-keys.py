import sys
import random


def index_of(a: list[int], key: int, lo: int, hi: int) -> int:
    """
    Performs a binary search on a sorted array and returns the index of the
    key. Returns -1 if not found.
    """
    if lo > hi:
        return -1
    mid = int(lo + (hi - lo) / 2)
    if key == a[mid]:
        return mid
    if key < a[mid]:
        return index_of(a, key, lo, mid - 1)
    else:
        return index_of(a, key, mid + 1, hi)


def rank(a: list[int], key: int) -> int:
    """
    Takes a sorted array of int values and returns the number of elements
    that are smaller than the key.
    """
    min_idx = -1
    idx = len(a) - 1
    while idx >= 0:
        idx = index_of(a, key, 0, idx)
        if idx >= 0:
            min_idx = idx
            idx -= 1
    return min_idx


def count(a: list[int], key: int) -> int:
    """
    Takes a sorted array of int values and returns the number of elements
    that are equal to the key.
    """
    rank_idx = rank(a, key)
    if rank_idx < 0:
        return -1
    idx = rank_idx
    while idx < len(a) and a[idx] == key:
        idx += 1
    return idx - rank_idx


if __name__ == "__main__":
    a = sorted([random.randint(0, 10) for _ in range(10)])
    key_idx = random.randint(0, len(a) - 1)
    key = a[key_idx]
    print("Array:", a, "Key:", key)
    print("Rank:", rank(a, key))
    print("Count:", count(a, key))

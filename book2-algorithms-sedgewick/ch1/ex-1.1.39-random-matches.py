# Experiment 1.1.39: Random Matches.
# TrialsResult: {1000: 0.0, 10000: 0.0, 100000: 2.5, 1000000: 25.0}
# The more random numbers we generate, if we use an uniform distribution,
# the bigger the probability of having repeated numbers across processes.

import sys
import random


def binary_search(a: list[int], key: int, lo: int = None, hi: int = None) -> int:
    if lo is None:
        lo = 0
    if hi is None:
        hi = len(a) - 1
    if lo > hi:
        return -1
    mid = int(lo + (hi - lo) / 2)
    if a[mid] == key:
        return mid
    if a[mid] < key:
        return binary_search(a, key, lo, mid - 1)
    else:
        return binary_search(a, key, mid + 1, hi)


def run_trials(trials: int) -> None:
    n = [1000, 10000, 100000, 1000000]
    sums = {n_i: 0 for n_i in n}
    for trial_i in range(trials):
        for n_i in n:
            print(f"Trial: {trial_i + 1}, Ni: {n_i}")
            a0 = [random.randint(100000, 999999) for _ in range(n_i)]
            a1 = [random.randint(100000, 999999) for _ in range(n_i)]
            for a0_i in a0:
                if binary_search(a1, a0_i) >= 0:
                    sums[n_i] += 1
    avgs = {}
    for n_i in n:
        avgs[n_i] = sums[n_i] / trials
    print("TrialsResult:", avgs)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Missing arguments.")
        sys.exit(1)
    trials = int(sys.argv[1])
    run_trials(trials)

# Algorithms: Sedgewick, Ch1 Ex 1.2.18 Variance for accumulator
# We calculate the variance using the sum of squares to prevent
# accumulating in memory all the numbers.
#
# $ python3 ex-1.2.18-variance-accumulator.py
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 1.00, variance: 0.00, stddev: 0.00
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 1.50, variance: 0.25, stddev: 0.50
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 2.00, variance: 0.67, stddev: 0.82
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 2.50, variance: 1.25, stddev: 1.12
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 3.00, variance: 2.00, stddev: 1.41
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 3.50, variance: 2.92, stddev: 1.71
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 4.00, variance: 4.00, stddev: 2.00
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 4.50, variance: 5.25, stddev: 2.29
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 5.00, variance: 6.67, stddev: 2.58
# numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], mean: 5.50, variance: 8.25, stddev: 2.87
#

import math


class Accumulator:
    def __init__(self):
        self.sum = 0
        self.sum_squares = 0
        self.count = 0

    def add_value(self, value: float) -> None:
        self.count += 1
        self.sum += value
        self.sum_squares += value**2

    def mean(self) -> float:
        return self.sum / self.count

    def variance(self) -> float:
        return (self.sum_squares - (self.sum**2) / self.count) / self.count

    def stddev(self) -> float:
        return math.sqrt(self.variance())


def run():
    numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    acc = Accumulator()
    for n in numbers:
        acc.add_value(n)
        print(
            f"numbers: {numbers}, mean: {acc.mean():.2f}, variance: {acc.variance():.2f}, stddev: {acc.stddev():.2f}"
        )


if __name__ == "__main__":
    run()

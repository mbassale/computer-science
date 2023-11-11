#
# Bad shuffling distribution does not yield equal probability to each ordening for n! possibilities.
#
# Simulation results for 1,000,000 runs:
# $ python ex-1.1.37-bad-shuffling.py 10 1000000
# === Good Distribution Simulation ===
# Target Frequency: m=10, n=1000000, prob=100000.00
#  100117.00   99953.00   99964.00   99589.00  100196.00  100082.00   99682.00  100390.00  100344.00   99683.00
#   99537.00  100157.00   99624.00  100363.00   99854.00   99600.00   99955.00   99899.00   99917.00  101094.00
#   99710.00  100112.00  100154.00   99830.00   99798.00   99885.00  100119.00   99962.00  100522.00   99908.00
#  100217.00  100175.00  100384.00   99691.00   99922.00  100032.00   99759.00   99762.00   99709.00  100349.00
#   99625.00  100634.00  100235.00  100144.00  100090.00   99986.00   99952.00   99711.00   99768.00   99855.00
#  100305.00   99744.00   99942.00  100265.00   99920.00  100008.00  100582.00   99853.00   99742.00   99639.00
#  100317.00   99853.00  100427.00   99614.00  100214.00   99736.00   99832.00  100211.00  100175.00   99621.00
#  100070.00   99897.00   99531.00  100529.00  100046.00  100253.00   99952.00  100080.00   99477.00  100165.00
#  100043.00   99545.00  100143.00  100270.00  100010.00  100285.00  100051.00  100110.00  100092.00   99451.00
#  100059.00   99930.00   99596.00   99705.00   99950.00  100133.00  100116.00  100022.00  100254.00  100235.00

# === Bad Distribution Simulation ===
# Target Frequency: m=10, n=1000000, prob=100000.00
#  100080.00   99849.00  100469.00   99440.00  100238.00   99947.00  100310.00  100339.00   99536.00   99792.00
#  128753.00   94043.00   94632.00   96146.00   95824.00   96671.00   96945.00   97926.00   99098.00   99962.00
#  119545.00  124271.00   90021.00   91361.00   91738.00   93421.00   95378.00   96008.00   97859.00  100398.00
#  111500.00  115696.00  120826.00   87534.00   88812.00   90481.00   92992.00   94996.00   97057.00  100106.00
#  104249.00  108647.00  112817.00  118387.00   86036.00   88053.00   91082.00   93689.00   96900.00  100140.00
#   97642.00  102465.00  107315.00  111840.00  118108.00   86397.00   88738.00   91877.00   95809.00   99809.00
#   92072.00   95778.00  101103.00  106473.00  112567.00  118482.00   87334.00   91081.00   95194.00   99916.00
#   86757.00   91091.00   95516.00  100450.00  106696.00  113458.00  120692.00   90196.00   94994.00  100150.00
#   81912.00   86279.00   90965.00   96287.00  101639.00  108485.00  115515.00  124374.00   94607.00   99937.00
#   77490.00   81881.00   86336.00   92082.00   98342.00  104605.00  111014.00  119514.00  128946.00   99790.00

# === Good Distribution Deviation % ===
# Target Frequency: m=10, n=1000000, prob=100000.00
#       0.12       0.05       0.04       0.41       0.20       0.08       0.32       0.39       0.34       0.32
#       0.46       0.16       0.38       0.36       0.15       0.40       0.04       0.10       0.08       1.09
#       0.29       0.11       0.15       0.17       0.20       0.11       0.12       0.04       0.52       0.09
#       0.22       0.18       0.38       0.31       0.08       0.03       0.24       0.24       0.29       0.35
#       0.38       0.63       0.24       0.14       0.09       0.01       0.05       0.29       0.23       0.14
#       0.30       0.26       0.06       0.27       0.08       0.01       0.58       0.15       0.26       0.36
#       0.32       0.15       0.43       0.39       0.21       0.26       0.17       0.21       0.18       0.38
#       0.07       0.10       0.47       0.53       0.05       0.25       0.05       0.08       0.52       0.17
#       0.04       0.46       0.14       0.27       0.01       0.29       0.05       0.11       0.09       0.55
#       0.06       0.07       0.40       0.29       0.05       0.13       0.12       0.02       0.25       0.24

# === Bad Distribution Deviation % ===
# Target Frequency: m=10, n=1000000, prob=100000.00
#       0.08       0.15       0.47       0.56       0.24       0.05       0.31       0.34       0.46       0.21
#      28.75       5.96       5.37       3.85       4.18       3.33       3.06       2.07       0.90       0.04
#      19.55      24.27       9.98       8.64       8.26       6.58       4.62       3.99       2.14       0.40
#      11.50      15.70      20.83      12.47      11.19       9.52       7.01       5.00       2.94       0.11
#       4.25       8.65      12.82      18.39      13.96      11.95       8.92       6.31       3.10       0.14
#       2.36       2.46       7.32      11.84      18.11      13.60      11.26       8.12       4.19       0.19
#       7.93       4.22       1.10       6.47      12.57      18.48      12.67       8.92       4.81       0.08
#      13.24       8.91       4.48       0.45       6.70      13.46      20.69       9.80       5.01       0.15
#      18.09      13.72       9.04       3.71       1.64       8.48      15.52      24.37       5.39       0.06
#      22.51      18.12      13.66       7.92       1.66       4.61      11.01      19.51      28.95       0.21

import sys
import random
from typing import Callable


def shuffle(a: list[float]) -> list[float]:
    for i in range(len(a)):
        r = i + int(random.uniform(0, len(a) - i))
        a[i], a[r] = a[r], a[i]
    return a


def shuffle_bad_distribution(a: list[float]) -> list[float]:
    for i in range(len(a)):
        r = random.randint(0, len(a) - 1)
        a[i], a[r] = a[r], a[i]
    return a


def shuffle_simulation(m: int, n: int, func: Callable) -> list[list[float]]:
    frequencies = [[0 for _ in range(m)] for _ in range(m)]
    for _ in range(n):
        a = [i for i in range(m)]
        b = func(a)
        for i in range(len(b)):
            row = b[i]
            frequencies[row][i] += 1
    return frequencies


def dump_matrix(m: int, n: int, a: list[list[float]]) -> None:
    print(f"Target Frequency: m={m}, n={n}, prob={(n / m):.2f}")
    for row in a:
        print(" ".join([f"{freq: 10.2f}" for freq in row]))
    print()


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Missing arguments")
        sys.exit(1)
    m = int(sys.argv[1])
    n = int(sys.argv[2])

    target_frequencies = [[n / m for _ in range(m)] for _ in range(m)]

    print("=== Good Distribution Simulation ===")
    frequencies1 = shuffle_simulation(m, n, shuffle)
    dump_matrix(m, n, frequencies1)

    print("=== Bad Distribution Simulation ===")
    frequencies2 = shuffle_simulation(m, n, shuffle_bad_distribution)
    dump_matrix(m, n, frequencies2)

    print("=== Good Distribution Deviation % ===")
    diff1 = [[0 for _ in range(m)] for _ in range(m)]
    for i in range(m):
        for j in range(m):
            diff1[i][j] = (
                abs(target_frequencies[i][j] - frequencies1[i][j])
                / target_frequencies[i][j]
                * 100.0
            )
    dump_matrix(m, n, diff1)

    print("=== Bad Distribution Deviation % ===")
    diff2 = [[0 for _ in range(m)] for _ in range(m)]
    for i in range(m):
        for j in range(m):
            diff2[i][j] = (
                abs(target_frequencies[i][j] - frequencies2[i][j])
                / target_frequencies[i][j]
                * 100.0
            )
    dump_matrix(m, n, diff2)

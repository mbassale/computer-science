import random

SIDES = 6


def dice_probabilities() -> list:
    """
    Returns an array with the probabilities of obtaining a certain sum when rolling two dices.
    """
    dist = [0 for _ in range(2 * SIDES + 1)]
    for i in range(1, SIDES + 1):
        for j in range(1, SIDES + 1):
            dist[i + j] += 1

    for k in range(2, 2*SIDES + 1):
        dist[k] /= SIDES*SIDES

    return dist


# Perform random experiments to check the previously calculated distribution.
expected_dist = dice_probabilities()
actual_dist = [0 for _ in range(2 * SIDES + 1)]
random.seed(42)
ROLLING_COUNT = 1000000
for i in range(ROLLING_COUNT):
    dice1 = random.randint(1, 6)
    dice2 = random.randint(1, 6)
    actual_dist[dice1 + dice2] += 1
for k in range(2, 2*SIDES + 1):
    actual_dist[k] /= ROLLING_COUNT

diff_dist = [abs(expected_dist[i] - actual_dist[i])
             for i in range(len(expected_dist))]

print('Expected Dice Probabilities: ', expected_dist)
print('Actual Dice Probabilities: ', actual_dist)
print('Diff: ', diff_dist)

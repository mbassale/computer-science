import random

SIDES = 6
SIMULATION_RUNS = 100000


def probability_distribution() -> list[float]:
    frequencies = [0 for _ in range(2 * SIDES + 1)]
    for i in range(1, SIDES):
        for j in range(1, SIDES):
            frequencies[i + j] += 1
    probabilities = [0 for _ in range(2 * SIDES + 1)]
    for k in range(2, 2 * SIDES):
        probabilities[k] = frequencies[k] / 36.0
    return probabilities


def dice_simulation() -> list[float]:
    frequencies = [0 for _ in range(2 * SIDES + 1)]
    for _ in range(SIMULATION_RUNS):
        dice_value1 = random.randint(1, 6)
        dice_value2 = random.randint(1, 6)
        frequencies[dice_value1 + dice_value2] += 1
    probabilities = [freq / SIMULATION_RUNS for freq in frequencies]
    return probabilities


if __name__ == "__main__":
    print("ProbabilityDistribution: ", [f"{i:.2f}" for i in probability_distribution()][2:])
    print("DiceRollSimulation:      ", [f"{i:.2f}" for i in dice_simulation()][2:])

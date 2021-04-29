import math
import time
import random
import os
from multiprocessing import Process, Array, cpu_count

SIDES = 6
random.seed(os.urandom(8))
expected_probabilities = [0.000,
                          0.000,
                          0.028,
                          0.056,
                          0.083,
                          0.111,
                          0.139,
                          0.167,
                          0.139,
                          0.111,
                          0.083,
                          0.056,
                          0.028]


def roll_dices_task(rolls_per_process: int, dice_counts: Array):
    for i in range(rolls_per_process):
        dice1 = random.randint(1, SIDES)
        dice2 = random.randint(1, SIDES)
        dice_counts[dice1 + dice2] += 1


def main():
    dice_counts = [0 for _ in range(2 * SIDES + 1)]
    number_processes = cpu_count()
    roll_count = 10000000
    print(f'Roll count: {roll_count}')
    rolls_per_process = math.ceil(roll_count / number_processes)
    print(f'Roll per process: {rolls_per_process}')

    start_time = time.time()
    results = [Array('I', [0 for _ in range(2 * SIDES + 1)], lock=False) for _ in range(number_processes)]
    processes = [Process(target=roll_dices_task, args=(rolls_per_process, results[i])) for i in range(number_processes)]
    for process in processes:
        process.start()
    for process in processes:
        process.join()
    end_time = time.time()
    print('--- %.3f ms ---' % ((end_time - start_time) * 1000))

    for i in range(len(dice_counts)):
        dice_counts[i] = 0
        for result in results:
            dice_counts[i] += result[i]

    actual_probabilities = [0 for _ in range(2 * SIDES + 1)]
    for i in range(len(dice_counts)):
        actual_probabilities[i] = dice_counts[i] / roll_count

    print('Actual Probabilities:')
    print(actual_probabilities)
    print(f'Probabilities Sum: {sum(actual_probabilities)}')
    diff = sum([abs(actual_probabilities[i] - expected_probabilities[i])
               for i in range(len(actual_probabilities))])
    print(f'Cummulative Diff: {diff}')


if __name__ == '__main__':
    main()

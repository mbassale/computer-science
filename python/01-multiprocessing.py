
import os
import time
from multiprocessing import Process, current_process, cpu_count


def square_sum(numbers):
    result = 0
    for number in numbers:
        result += number * number
        time.sleep(0.5)
    print(f'Sum of squares: {result}')


if __name__ == '__main__':
    number_processes = cpu_count()
    print(f'Number of cores: {number_processes}')
    processes = []
    numbers = range(10)
    for i in range(number_processes):
        process = Process(target=square_sum, args=(numbers,))
        processes.append(process)
        process.start()

    for process in processes:
        process.join()

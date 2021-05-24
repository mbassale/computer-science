from math import floor
import sys
import random
import time

class ShellSort:

    def sort(self, items) -> None:
        h = 1
        while h < len(items) // 3:
            h = 3 * h + 1 #  1, 4, 13, 40, 121, 364, 1093, ...

        while h >= 1:
            for i in range(h, len(items)):
                j = i
                while j >= h and items[j] < items[j - h]:
                    self.swap(items, j, j - h)
                    j -= h
            h = h // 3

    def swap(self, items, i, j) -> None:
        items[i], items[j] = items[j], items[i]


def main():
    print('Shell Sort')

    if len(sys.argv) < 2:
        print('Missing number of items.')
        exit(1)
    
    number_items = int(sys.argv[1])
    print('Number of Items: ', number_items)

    print('Generating numbers... ', end='', flush=True)
    numbers = [random.randint(0, 1000000) for _ in range(number_items)]
    print('Done.')

    if number_items <= 100:
        print('Numbers: ', ', '.join((str(n) for n in numbers)))
    
    print('Sorting... ', end='', flush=True)
    shell_sort = ShellSort()
    t1 = time.time()
    shell_sort.sort(numbers)
    t2 = time.time()
    print('Done.')

    print('Running time: ', (t2 - t1), 'secs.')

    if number_items <= 100:
        print('Numbers: ', ', '.join((str(n) for n in numbers)))

    print('Checking... ', end='', flush=True)
    for i in range(len(numbers) - 1):
        if numbers[i] > numbers[i + 1]:
            print('\nBad ordering: ', numbers[i], ', ', numbers[i + 1])
            exit(1)
    print('Done.')

if __name__ == '__main__':
    main()

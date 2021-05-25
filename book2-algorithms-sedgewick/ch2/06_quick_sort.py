from math import floor
import sys
import random
import time
from typing import Any, Sequence

class QuickSort:

    def sort(self, items: Sequence[Any]) -> None:
        self._sort(items, 0, len(items) - 1)
    
    def _sort(self, items: Sequence[Any], left: int, right: int) -> None:
        if left >= right: return
        if left < 0 or right >= len(items): return
        j = self._partition(items, left, right)
        self._sort(items, left, j - 1)
        self._sort(items, j + 1, right)

    def _partition(self, items: Sequence[Any], left: int, right: int) -> None:
        i = left
        j = right + 1
        v = items[left]
        while True:
            i += 1
            while items[i] < v:
                if i >= right: break
                i += 1
            j -= 1
            while items[j] > v:
                if j <= left: break
                j -= 1
            if i >= j: break
            items[i], items[j] = items[j], items[i]
        items[left], items[j] = items[j], items[left]
        return j


def main():
    print('QuickSort.')

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
    quick_sort = QuickSort()
    t1 = time.time()
    quick_sort.sort(numbers)
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

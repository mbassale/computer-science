from math import floor
import sys
import random
import time

class MergeSort:

    def sort(self, items) -> None:
        aux = items[:]
        self._merge_sort(items, aux, 0, len(items) - 1)

    def _merge_sort(self, items, aux, left, right) -> None:
        if left >= right:
            return
        mid = left + floor((right - left) / 2.0)
        self._merge_sort(items, aux, left, mid)
        self._merge_sort(items, aux, mid + 1, right)
        self._merge(items,aux, left, mid, right)

    def _merge(self, items, aux, left, mid, right) -> None:
        # copy elements to aux.
        for i in range(left, right + 1):
            aux[i] = items[i]
        
        # merge both subarrays.
        i = left
        j = mid + 1
        for k in range(left, right + 1):
            if i > mid:
                items[k] = aux[j]
                j += 1
            elif j > right:
                items[k] = aux[i]
                i += 1
            elif aux[i] > aux[j]:
                items[k] = aux[j]
                j += 1
            else:
                items[k] = aux[i]
                i += 1
            k += 1


def main():
    print('Merge Sort')

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
    merge_sort = MergeSort()
    t1 = time.time()
    merge_sort.sort(numbers)
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

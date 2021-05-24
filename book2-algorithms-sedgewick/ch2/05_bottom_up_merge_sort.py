from math import floor
import sys
import random
import time

class BottomUpMergeSort:

    def sort(self, items) -> None:
        aux = items[:]
        sz = 1
        while sz < len(items):
            for lo in range(0, len(items) - sz, 2 * sz):
                self._merge(items, aux, lo, lo + sz - 1, min(lo + 2 * sz - 1, len(items) - 1))
            sz += sz

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
    print('Bottom Up Merge Sort')

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
    bottom_up_merge_sort = BottomUpMergeSort()
    t1 = time.time()
    bottom_up_merge_sort.sort(numbers)
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

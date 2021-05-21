import sys
import random
import time

class SelectionSort:

    def sort(self, items) -> None:
        for i in range(len(items)):
            min_index = i
            for j in range(i + 1, len(items)):
                if items[j] < items[min_index]:
                    min_index = j
            self.swap(items, i, min_index)

    def swap(self, items, i, j) -> None:
        items[i], items[j] = items[j], items[i]


def main():
    print('Selection Sort')

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
    selection_sort = SelectionSort()
    t1 = time.time()
    selection_sort.sort(numbers)
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

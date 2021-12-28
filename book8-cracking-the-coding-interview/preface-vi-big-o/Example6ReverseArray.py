import random


def reverse(arr: list):
    """
    Reverses the array in-place (non-pythonic)
    """
    for i in range(len(arr) // 2):
        other_index = len(arr) - i - 1
        arr[i], arr[other_index] = arr[other_index], arr[i]


def run():
    lst1 = list(range(10))
    print('List:', lst1)
    reverse(lst1)
    print('ListReversed:', lst1)

    lst2 = list(range(20))
    random.shuffle(lst2)
    print('List2:', lst2)
    reverse(lst2)
    print('List2Reversed:', lst2)


if __name__ == '__main__':
    run()

from pprint import pprint

def numberOfWays(array, k):
    numberCounts = {}
    for num in array:
        if num in numberCounts:
            numberCounts[num] += 1
        else:
            numberCounts[num] = 1
    numberOfPairs = 0
    for num in array:
        otherNum = k - num
        if otherNum in numberCounts:
            numberOfPairs += numberCounts[otherNum]
            if otherNum == num:
                numberOfPairs -= 1
    return int(numberOfPairs / 2)

tests = [
    { 'array': [1, 2, 3, 4, 3], 'k': 6, 'expected': 2 },
    { 'array': [1, 5, 3, 3, 3], 'k': 6, 'expected': 4 },
]

for test in tests:
    result = numberOfWays(test['array'], test['k'])
    print('array:', test['array'], 'k', test['k'], 'expected:', test['expected'], 'result:', result)
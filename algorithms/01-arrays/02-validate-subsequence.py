
def isValidSubsequence(array, sequence):
    sequenceIndex = 0
    for num in array:
        if sequenceIndex < len(sequence) and num == sequence[sequenceIndex]:
            sequenceIndex += 1
    return sequenceIndex == len(sequence)


testCases = [
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [1, 6, -1, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 25, 6, -1, 8, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 6, -1, 8, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [22, 25, 6]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [1, 6, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, -1, 8, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [25]},
    {"array": [1, 1, 1, 1, 1], "sequence": [1, 1, 1]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 25, 6, -1, 8, 10, 12]}
]

for testCase in testCases:
    print('Array:', testCase['array'], 'Sequence:', testCase['sequence'], 'isValidSubsequence:', isValidSubsequence(testCase['array'], testCase['sequence']))

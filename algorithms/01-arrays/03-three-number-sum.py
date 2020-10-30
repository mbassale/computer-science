
def threeNumberSum(array, targetSum):
    array.sort()
    result = []
    for i in range(len(array)):
        left = i + 1
        right = len(array) - 1
        while left < right:
            currentSum = array[i] + array[left] + array[right]
            if currentSum == targetSum:
                result.append((array[i], array[left], array[right]))
                left += 1
                right -= 1
            elif currentSum < targetSum:
                left += 1
            elif currentSum > targetSum:
                right -= 1
    return result

testCases = [
    {"array": [12, 3, 1, 2, -6, 5, -8, 6], "targetSum": 0},
    {"array": [1, 2, 3], "targetSum": 6},
    {"array": [1, 2, 3], "targetSum": 7},
    {"array": [8, 10, -2, 49, 14], "targetSum": 57},
    {"array": [12, 3, 1, 2, -6, 5, 0, -8, -1], "targetSum": 0},
    {"array": [12, 3, 1, 2, -6, 5, 0, -8, -1, 6], "targetSum": 0},
    {"array": [12, 3, 1, 2, -6, 5, 0, -8, -1, 6, -5], "targetSum": 0},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 18},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 32},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 33},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 5}
]

for testCase in testCases:
    result = threeNumberSum(testCase['array'], testCase['targetSum'])
    resultOk = []
    for resultItem in result:
        resultOk.append(sum(resultItem) == testCase['targetSum'])
    print('Array:', testCase['array'], 'TargetSum:', testCase['targetSum'], 'ThreeNumberSum:', result, 'ResultOK:', resultOk)


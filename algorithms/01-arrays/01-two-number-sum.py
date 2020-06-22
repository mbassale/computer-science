
def twoNumberSum1(array, targetSum):
    for i in range(len(array)):
        num1 = array[i]
        for j in range(i + 1, len(array)):
            num2 = array[j]
            if num1 + num2 == targetSum:
                return [num1, num2]
    return []

def twoNumberSum2(array, targetSum):
    seen = {}
    for num1 in array:
        num2 = targetSum - num1
        if num2 in seen:
            return [num1, num2]
        seen[num1] = True
    return []

def twoNumberSum3(array, targetSum):
    array.sort()
    left = 0
    right = len(array) - 1
    while left < right:
        currentSum = array[left] + array[right]
        if currentSum == targetSum:
            return [array[left], array[right]]
        elif currentSum < targetSum:
            left += 1
        elif currentSum > targetSum:
            right -= 1
    return []


testCases = [
    {"array": [3, 5, -4, 8, 11, 1, -1, 6], "targetSum": 10},
    {"array": [4, 6], "targetSum": 10},
    {"array": [4, 6, 1], "targetSum": 5},
    {"array": [4, 6, 1, -3], "targetSum": 3},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9], "targetSum": 17},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 18},
    {"array": [-7, -5, -3, -1, 0, 1, 3, 5, 7], "targetSum": -5},
    {"array": [-21, 301, 12, 4, 65, 56, 210, 356, 9, -47], "targetSum": 163},
    {"array": [-21, 301, 12, 4, 65, 56, 210, 356, 9, -47], "targetSum": 164},
    {"array": [3, 5, -4, 8, 11, 1, -1, 6], "targetSum": 15}
]

for testCase in testCases:
    print('twoNumberSum1:', twoNumberSum1(testCase['array'], testCase['targetSum']))
    print('twoNumberSum2:', twoNumberSum2(testCase['array'], testCase['targetSum']))
    print('twoNumberSum3:', twoNumberSum3(testCase['array'], testCase['targetSum']))

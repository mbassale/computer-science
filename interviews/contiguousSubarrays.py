
def countSubarrays(arr):
    n = len(arr)
    result = [1] * n
    stack = [-1]

    # left
    for i in range(n):
        while len(stack) > 1 and arr[stack[-1]] < arr[i]:
            stack.pop()
        result[i] += i - stack[-1] - 1
        stack.append(i)

    # right
    stack = [n]
    for i in range(n - 1, -1, -1):
        while len(stack) > 1 and arr[stack[-1]] < arr[i]:
            stack.pop()
        result[i] += stack[-1] - i - 1
        stack.append(i)

    return result

tests = [
    { 'array': [3, 4, 1, 6, 2], 'expected': [1, 3, 1, 5, 1] },
    { 'array': [2, 4, 7, 1, 5, 3], 'expected': [1, 2, 6, 1, 3, 1] }
]

for test in tests:
    result = countSubarrays(test['array'])
    print('array:', test['array'], 'expected:', test['expected'], 'result:', result)

def templateString(s, template):
    charCounts = {}
    for char in s:
        if char in charCounts:
            charCounts[char] += 1
        else:
            charCounts[char] = 1
    result = ''
    for char in template:
        if char in charCounts:
            result += char * charCounts[char]
    return result


tests = [
    { 's': 'aabbcddd', 'template': 'cdafb', 'expected': 'cdddaabb' },
    { 's': 'cccbaaaadddd', 'template': 'abc', 'expected': 'aaaabccc' }
]

for test in tests:
    result = templateString(test['s'], test['template'])
    print('s:', test['s'], 'template:', test['template'], 'expected:', test['expected'], 'result:', result)
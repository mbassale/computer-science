
function singleCycleCheck(array, firstIndex = 0) {
    let currentIndex = firstIndex;
    let nextIndex = 0;
    let visitedIndices = 0;
    while (visitedIndices < array.length) {
        nextIndex = (currentIndex + array[currentIndex]) % array.length;
        if (nextIndex < 0) {
            nextIndex = array.length + nextIndex;
        }
        currentIndex = nextIndex;
        visitedIndices++;
    }
    return currentIndex == 0;
}

const tests = [
    { array: [2, 3, 1, -4, -4, 2], expected: true },
    { array: [2, 2, -1], expected: true },
    { array: [1, 1, 1, 1, 1], expected: true },
    { array: [1, 1, 0, 1, 1], expected: false },
    { array: [10, 11, -6, -23, -2, 3, 88, 908, -26], expected: true },
    { array: [10, 11, -6, -23, -2, 3, 88, 909, -26], expected: false }
];

for (const test of tests) {
    const result = singleCycleCheck(test.array);
    const ok = result === test.expected;
    console.log('array:', test.array, 'expected:', test.expected, 'result:', result, 'ok:', ok);
}

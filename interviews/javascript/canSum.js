const {performance} = require('perf_hooks');

/**
 * Can the number n be generated by adding any times the numbers of the array?
 */
function canSum(n, array, memoize = {}) {
    if (n in memoize) {
        return memoize[n];
    }
    if (n == 0) {
        return true;
    }
    // there is no number if array that can be added to form n
    if (n < Math.min(...array)) {
        return false;
    }
    for (const otherNum of array) {
        const newNum = n - otherNum;
        if (newNum >= 0 && canSum(newNum, array, memoize)) {
            memoize[n] = true;
            return memoize[n];
        }
    }
    memoize[n] = false;
    return memoize[n];
}

function measure(n, array, func) {
    const startTime = performance.now();
    const result = func(n, array);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { n: 7, array: [2, 3], expected: true },
    { n: 7, array: [5, 3, 4, 7], expected: true },
    { n: 7, array: [2, 4], expected: false },
    { n: 8, array: [2, 3, 5], expected: true },
    { n: 300, array: [7, 14], expected: false }
];

for (const test of tests) {
    const [deltaTime, result] = measure(test.n, test.array, canSum);
    console.log('n:', test.n, 'array:', test.array, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}
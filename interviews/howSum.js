const {performance} = require('perf_hooks');

function howSum(n, array, memoize = {}) {
    // memoize optimization
    if (n in memoize) return memoize[n];
    // base case of iteration
    if (n === 0) return [];
    // if n is less than any member of the array
    if (n < 0) return null;

    for (const num of array) {
        const remainder = n - num;
        const result = howSum(remainder, array, memoize);
        if (result !== null) {
            result.push(num);
            memoize[num] = result;
            return result;
        }
    }
    memoize[n] = null;
    return null;
}

function measure(n, array, func) {
    const startTime = performance.now();
    const result = func(n, array);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { n: 7, array: [2, 3], expected: [2, 2, 3] },
    { n: 7, array: [5, 3, 4, 7], expected: [3, 4] },
    { n: 7, array: [2, 4], expected: null },
    { n: 8, array: [2, 3, 5], expected: [2, 2, 2, 2] },
    { n: 300, array: [7, 14], expected: null }
];

for (const test of tests) {
    const [deltaTime, result] = measure(test.n, test.array, howSum);
    console.log('n:', test.n, 'array:', test.array, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}

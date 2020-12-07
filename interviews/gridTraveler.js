const {performance} = require('perf_hooks');

function gridTraveler(m, n, memoize = {}) {
    const key = Math.min(m, n) + ',' + Math.max(m, n);
    if (key in memoize) {
        return memoize[key];
    }
    if (m == 0 || n == 0) {
        return 0;
    }
    if (m == 1 && n == 1) {
        return 1;
    }
    const bottomWays = gridTraveler(m - 1, n, memoize);
    const rightWays = gridTraveler(m, n - 1, memoize);
    memoize[key] = bottomWays + rightWays;
    return memoize[key];
}

function measure(m, n, func) {
    const startTime = performance.now();
    const result = func(m, n);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { m: 1, n: 1, expected: 1 },
    { m: 2, n: 3, expected: 3 },
    { m: 3, n: 2, expected: 3 },
    { m: 3, n: 3, expected: 6 },
    { m: 18, n: 18, expected: 2333606220 }
];

for (const test of tests) {
    const [deltaTime, result] = measure(test.m, test.n, gridTraveler);
    console.log('m:', test.m, 'n:', test.n, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}
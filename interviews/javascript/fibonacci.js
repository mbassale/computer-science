const {performance} = require('perf_hooks');

function fib(n, memoize = {}) {
    if (n <= 2) return 1;
    if (n in memoize) return memoize[n];
    const result = fib(n - 1, memoize) + fib(n - 2, memoize);
    memoize[n] = result;
    return result;
}

function fib2(n) {
    if (n <= 2) return 1;
    let minus1 = 1;
    let minus2 = 1;
    let currentNumber = 0;
    for (let i = 3; i <= n; i++) {
        currentNumber = minus1 + minus2;
        minus2 = minus1;
        minus1 = currentNumber;
    }
    return currentNumber;
}

function measure(n, func) {
    const startTime = performance.now();
    const result = func(n);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { n: 1, expected: 1 },
    { n: 2, expected: 1 },
    { n: 3, expected: 2 },
    { n: 10, expected: 55 },
    { n: 20, expected: 6765 },
    { n: 50, expected: 12586269025 },
    { n: 70, expected: 190392490709135 }
];

for (const test of tests) {
    const [timeDelta1, result1] = measure(test.n, fib);
    const [timeDelta2, result2] = measure(test.n, fib2);
    console.log('n:', test.n, 'expected:', test.expected, 
        'result1:', result1, 'timeDelta1:', timeDelta1, 
        'result2:', result2, 'timeDelta2:', timeDelta2);
}

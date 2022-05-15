const {performance} = require('perf_hooks');

function fib(n) {
    const table = new Array(n + 1).fill(0);
    table[0] = 0;
    table[1] = 1;

    for (let i = 2; i < table.length; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }

    return table[n];
}

function fib2(n) {
    let fibMinus2 = 0;
    let fibMinus1 = 1;
    let fibOfN = 0;
    let i = 2;
    while (i <= n) {
        fibOfN = fibMinus1 + fibMinus2; // fib(n) = fib(n - 1) + fib(n - 2)
        fibMinus2 = fibMinus1; // fib(n - 2) = fib(n - 1)
        fibMinus1 = fibOfN; // fib(n - 1) = fib(n)
        i++;
    }
    return fibOfN;
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

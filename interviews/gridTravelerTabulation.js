const {performance} = require('perf_hooks');

// Time O(m*n) | Space O(m*n)
function gridTraveler(m, n) {
    const table = new Array(m + 1).fill(null);
    for (let i = 0; i < table.length; i++) {
        table[i] = new Array(n + 1).fill(0);
    }
    console.log(table);
    table[1][1] = 1; // base condition
    for (let i = 1; i < table.length; i++) {
        for (let j = 1; j < table[i].length; j++) {
            if (i + 1 < table.length) {
                table[i + 1][j] += table[i][j];
            }
            if (j + 1 < table[i].length) {
                table[i][j + 1] += table[i][j];
            }
        }
    }
    return table[m][n];
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
const {performance} = require('perf_hooks');

/**
 * Can the number n be generated by adding any times the numbers of the array?
 */
// n: number, m: length of array. Time O(n * m) | Space O(n)
function canSumTabulation(n, array) {
    const table = Array(n + 1).fill(false);
    // if we take zero elements, we can generate the number zero
    table[0] = true;

    for (let currentNumber = 0; currentNumber <= n; currentNumber++) {
        if (table[currentNumber] === false) continue;

        for (let j = 0; j < array.length; j++) {
            const num = array[j];
            const nextNumber = currentNumber + num;
            if (nextNumber < table.length) {
                table[nextNumber] = true;
            }
        }
    }

    return table[n];
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
    const [deltaTime, result] = measure(test.n, test.array, canSumTabulation);
    console.log('n:', test.n, 'array:', test.array, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}
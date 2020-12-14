const {performance} = require('perf_hooks');

// n: targetSum, m: numbers length.
function bestSumTabulation(targetSum, numbers) {
    const table = Array(targetSum + 1).fill(null);
    // initial condition.
    table[0] = [];

    for (let currentNumber = 0; currentNumber <= targetSum; currentNumber++) {
        // skip if we can't generate the number
        if (table[currentNumber] === null) continue;
        for (let i = 0; i < numbers.length; i++) {
            const num = numbers[i];
            const nextNumber = currentNumber + num;
            if (nextNumber <= targetSum) {
                const currentSolution = table[nextNumber];
                const newSolution = [...table[currentNumber], num];
                if (currentSolution === null || newSolution.length < currentSolution.length) {
                    table[nextNumber] = newSolution;
                }
            }
        }
    }

    return table[targetSum];
}

function measure(n, array, func) {
    const startTime = performance.now();
    const result = func(n, array);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { n: 7, array: [5, 3, 4, 7], expected: [7] },
    { n: 8, array: [2, 3, 5], expected: [3, 5] },
    { n: 8, array: [1, 4, 5], expected: [4, 4] },
    { n: 100, array: [1, 2, 5, 25], expected: [25, 25, 25, 25] }
];

for (const test of tests) {
    const [deltaTime, result] = measure(test.n, test.array, bestSumTabulation);
    console.log('n:', test.n, 'array:', test.array, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}

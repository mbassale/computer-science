const {performance} = require('perf_hooks');

// n: targetSum, m: numbers length => O(n*m^2) Time | O(m^2) space
function bestSum(targetSum, numbers, memoize = {}) {
    if (targetSum in memoize) return memoize[targetSum];
    if (targetSum == 0) return [];
    if (targetSum < 0) return null;

    let bestResult = null;
    for (const num of numbers) {
        const remainder = targetSum - num;
        const result = bestSum(remainder, numbers, memoize);
        if (result !== null) {
            const updatedResult = result.slice();
            updatedResult.push(num);
            if (bestResult === null || updatedResult.length < bestResult.length) {
                bestResult = updatedResult;
            }
        }
    }

    memoize[targetSum] = bestResult;
    return bestResult;
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
    const [deltaTime, result] = measure(test.n, test.array, bestSum);
    console.log('n:', test.n, 'array:', test.array, 'expected:', test.expected, 'result:', result, 'deltaTime:', deltaTime);
}

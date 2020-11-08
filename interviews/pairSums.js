
// O(n) time | O(n) space
function numberOfWays(array, k) {
    const numberCounts = {};
    for (const number of array) {
        if (number in numberCounts) {
            numberCounts[number] += 1;
        } else {
            numberCounts[number] = 1;
        }
    }
    let numberOfPairs = 0;
    for (let i = 0; i < array.length; i++) {
        const currentNumber = array[i];
        const otherNumber = k - currentNumber;
        if (otherNumber in numberCounts) {
            numberOfPairs += numberCounts[otherNumber];
            if (currentNumber == otherNumber) {
                numberOfPairs--;
            }
        }
    }
    return numberOfPairs / 2;
}

const tests = [
    { array: [1, 2, 3, 4, 3], k: 6, expected: 2 },
    { array: [1, 5, 3, 3, 3], k: 6, expected: 4 }
];

for (const test of tests) {
    const result = numberOfWays(test.array, test.k);
    console.log('array:', test.array, 'k:', test.k, 'Expected:', test.expected, 'Result:', result);
}
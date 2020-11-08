
/**
 * Naive solution n^2
 */
function countSubarrays(arr) {
    const result = [];
    for (let i = 0; i < arr.length; i++) {
        const currentNumber = arr[i];
        let leftArraysCount = 1;
        let rightArraysCount = 1;
        for (let j = i - 1; j >= 0; j--) {
            if (arr[j] <= currentNumber) {
                leftArraysCount++;
            } else {
                break;
            }
        }
        for (let k = i + 1; k < arr.length; k++) {
            if (arr[k] <= currentNumber) {
                rightArraysCount++;
            } else {
                break;
            }
        }
        result[i] = leftArraysCount + rightArraysCount - 1;
    }
    return result;
}

/**
 * Using a stack of previously explored indexes.
 */
function countSubarrays2(arr) {
    const result = [];
    for (let i = 0; i < arr.length; i++) {
        result[i] = 1;
    }
    
    // from the left
    let indexStack = [-1];
    for (let i = 0; i < arr.length; i++) {
        const currentNumber = arr[i];
        while (indexStack.length > 1 && arr[indexStack[indexStack.length - 1]] < currentNumber) {
            indexStack.pop();
        }
        result[i] += i - indexStack[indexStack.length - 1] - 1;
        indexStack.push(i);
    }

    // from the right
    indexStack = [arr.length];
    for (let i = arr.length - 1; i >= 0; i--) {
        const currentNumber = arr[i];
        while (indexStack.length > 1 && arr[indexStack[indexStack.length - 1]] < currentNumber) {
            indexStack.pop();
        }
        result[i] += indexStack[indexStack.length - 1] - i - 1;
        indexStack.push(i);
    }

    return result;
}

const tests = [
    { array: [3, 4, 1, 6, 2], expected: [1, 3, 1, 5, 1] },
    { array: [2, 4, 7, 1, 5, 3], expected: [1, 2, 6, 1, 3, 1] }
];

for (const test of tests) {
    const result = countSubarrays(test.array);
    const result2 = countSubarrays2(test.array);
    console.log('array:', test.array, 'expected:', test.expected, 'result:', result, 'result2:', result2);
}
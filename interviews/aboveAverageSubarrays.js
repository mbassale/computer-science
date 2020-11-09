
function getAverage(arr, i, j) {
    let sum = 0;
    for (let k = i; k <= j; k++) {
        sum += arr[k];
    }
    return sum / (j - i + 1);
}

function getAverageOther(arr, i, j) {
    let sum = 0;
    let count = 0;
    for (let k = 0; k < i; k++) {
        sum += arr[k];
        count++;
    }
    for (let k = j + 1; k < arr.length; k++) {
        sum += arr[k];
        count++;
    }
    if (count == 0) return 0;
    return sum / count;
}

function aboveAverageSubarrays(arr) {
    const result = [];
    for (let i = 0; i < arr.length; i++) {
        for (let j = i; j < arr.length; j++) {
            const average = getAverage(arr, i, j);
            const averageOther = getAverageOther(arr, i, j);
            if (average > averageOther) {
                result.push([i + 1, j + 1]);
            }
        }
    }
    return result;
}

const tests = [
    { array: [3, 4, 2], expected: [[1, 2], [1, 3], [2, 2]] }
];

for (const test of tests) {
    const result = aboveAverageSubarrays(test.array);
    console.log('array:', test.array, 'expected:', test.expected, 'result:', result);
}
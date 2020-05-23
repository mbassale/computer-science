
/**
 * Brute Force
 * @param {*} array 
 * @param {*} targetSum 
 */
function twoNumberSum(array, targetSum) {
    for (let i = 0; i < array.length; i++) {
        for (let j = i + 1; j < array.length; j++) {
            if (array[i] + array[j] === targetSum) {
                return [array[i], array[j]];
            }
        }
    }
    return [];
}

/**
 * Dynamic Programming
 * @param {*} array 
 * @param {*} targetSum 
 */
function twoNumberSum2(array, targetSum) {
    const hash = {};
    for (let i = 0; i < array.length; i++) {
        const otherNumber = targetSum - array[i];
        if (hash[otherNumber.toString()]) {
            return [otherNumber, array[i]];
        }
        hash[array[i].toString()] = true;
    }
    return [];
}

/**
 * Sorting
 * @param {*} array 
 * @param {*} targetSum 
 */
function twoNumberSum3(array, targetSum) {
    array.sort((a, b) => a - b);
    let left = 0;
    let right = array.length - 1;
    while (left < right) {
        const sum = array[left] + array[right];
        if (sum === targetSum) {
            return [array[left], array[right]];
        }
        if (sum < targetSum) {
            left++;
        }
        if (sum > targetSum) {
            right--;
        }
    }
    return [];
}

const testCases = [
    {"array": [3, 5, -4, 8, 11, 1, -1, 6], "targetSum": 10},
    {"array": [4, 6], "targetSum": 10},
    {"array": [4, 6, 1], "targetSum": 5},
    {"array": [4, 6, 1, -3], "targetSum": 3},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9], "targetSum": 17},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 18},
    {"array": [-7, -5, -3, -1, 0, 1, 3, 5, 7], "targetSum": -5},
    {"array": [-21, 301, 12, 4, 65, 56, 210, 356, 9, -47], "targetSum": 163},
    {"array": [-21, 301, 12, 4, 65, 56, 210, 356, 9, -47], "targetSum": 164},
    {"array": [3, 5, -4, 8, 11, 1, -1, 6], "targetSum": 15}
];
testCases.forEach(testCase => {
    console.log('TestCase:', testCase);
    console.log('Result1:', twoNumberSum(testCase.array, testCase.targetSum));
    console.log('Result2:', twoNumberSum2(testCase.array, testCase.targetSum));
    console.log('Result3:', twoNumberSum3(testCase.array, testCase.targetSum));
})
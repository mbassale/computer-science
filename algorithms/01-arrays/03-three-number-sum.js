
function threeNumberSum(array, targetSum)
{
    const result = [];
    array.sort((a, b) => a - b);
    for (let i = 0; i < array.length; i++) {
        let left = i + 1;
        let right = array.length - 1;
        while (left < right) {
            const sum = array[i] + array[left] + array[right];
            if (sum === targetSum) {
                result.push([array[i], array[left], array[right]]);
                left++;
                right--;
            }
            if (sum < targetSum) {
                left++;
            }
            if (sum > targetSum) {
                right--;
            }
        }
    }
    return result;
}

const testCases = [
    {"array": [12, 3, 1, 2, -6, 5, -8, 6], "targetSum": 0},
    {"array": [1, 2, 3], "targetSum": 6},
    {"array": [1, 2, 3], "targetSum": 7},
    {"array": [8, 10, -2, 49, 14], "targetSum": 57},
    {"array": [12, 3, 1, 2, -6, 5, 0, -8, -1], "targetSum": 0},
    {"array": [12, 3, 1, 2, -6, 5, 0, -8, -1, 6], "targetSum": 0},
    {"array": [12, 3, 1, 2, -6, 5, 0, -8, -1, 6, -5], "targetSum": 0},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 18},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 32},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 33},
    {"array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 15], "targetSum": 5}
];
testCases.forEach(testCase => {
    console.log('TestCase:', testCase);
    console.log('Result:', threeNumberSum(testCase.array, testCase.targetSum));
});
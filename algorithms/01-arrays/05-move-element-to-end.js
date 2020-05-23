
function moveElementToEnd(array, toMove) {
    let left = 0;
    let right = array.length - 1;
    while (left < right) {
        if (array[left] !== toMove) {
            left++;
        } else if (array[right] === toMove) {
            right--;
        } else {
            // swap values
            const temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    return array;
}

const testCases = [
    {"array": [2, 1, 2, 2, 2, 3, 4, 2], "toMove": 2},
    {"array": [], "toMove": 3},
    {"array": [1, 2, 4, 5, 6], "toMove": 3},
    {"array": [3, 3, 3, 3, 3], "toMove": 3},
    {"array": [3, 1, 2, 4, 5], "toMove": 3},
    {"array": [1, 2, 4, 5, 3], "toMove": 3},
    {"array": [1, 2, 3, 4, 5], "toMove": 3},
    {"array": [5, 5, 5, 5, 5, 5, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12], "toMove": 5},
    {"array": [1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 5, 5, 5, 5, 5, 5], "toMove": 5},
    {"array": [5, 1, 2, 5, 5, 3, 4, 6, 7, 5, 8, 9, 10, 11, 5, 5, 12], "toMove": 5}
];
testCases.forEach(testCase => {
    console.log('TestCase:', testCase);
    console.log('Result:', moveElementToEnd(testCase.array, testCase.toMove));
});
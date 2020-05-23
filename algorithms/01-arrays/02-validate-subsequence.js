
function isValidSubsequence(array, sequence) {
    let sequenceIndex = 0;
    for (let i = 0; i < array.length; i++) {
        if (array[i] == sequence[sequenceIndex]) {
            sequenceIndex++;
        }
    }
    return sequenceIndex === sequence.length;
}

const testCases = [
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [1, 6, -1, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 25, 6, -1, 8, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 6, -1, 8, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [22, 25, 6]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [1, 6, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, -1, 8, 10]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [25]},
    {"array": [1, 1, 1, 1, 1], "sequence": [1, 1, 1]},
    {"array": [5, 1, 22, 25, 6, -1, 8, 10], "sequence": [5, 1, 22, 25, 6, -1, 8, 10, 12]}
];
testCases.forEach(testCase => {
    console.log('TestCase:', testCase);
    console.log('Result:', isValidSubsequence(testCase.array, testCase.sequence));
});
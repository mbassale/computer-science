
function smallestDifference(array1, array2)
{
    array1.sort((a, b) => a - b);
    array2.sort((a, b) => a - b);

    let result = [];
    let minDiff = Infinity;
    let index1 = 0;
    let index2 = 0;
    while (index1 < array1.length && index2 < array2.length) {
        const diff = Math.abs(array1[index1] - array2[index2]);
        if (diff === 0) {
            return [array1[index1], array2[index2]];
        }
        if (diff < minDiff) {
            minDiff = diff;
            result = [array1[index1], array2[index2]];
        }
        if (array1[index1] < array2[index2]) {
            index1++;
        } else if (array1[index1] > array2[index2]) {
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return result;
}

testCases = [
    {"arrayOne": [-1, 5, 10, 20, 28, 3], "arrayTwo": [26, 134, 135, 15, 17]},
    {"arrayOne": [-1, 5, 10, 20, 3], "arrayTwo": [26, 134, 135, 15, 17]},
    {"arrayOne": [10, 0, 20, 25], "arrayTwo": [1005, 1006, 1014, 1032, 1031]},
    {"arrayOne": [10, 0, 20, 25, 2200], "arrayTwo": [1005, 1006, 1014, 1032, 1031]},
    {"arrayOne": [10, 0, 20, 25, 2000], "arrayTwo": [1005, 1006, 1014, 1032, 1031]},
    {"arrayOne": [240, 124, 86, 111, 2, 84, 954, 27, 89], "arrayTwo": [1, 3, 954, 19, 8]},
    {"arrayOne": [0, 20], "arrayTwo": [21, -2]},
    {"arrayOne": [10, 1000], "arrayTwo": [-1441, -124, -25, 1014, 1500, 660, 410, 245, 530]},
    {"arrayOne": [10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123], "arrayTwo": [-1441, -124, -25, 1014, 1500, 660, 410, 245, 530]},
    {"arrayOne": [10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123, 530], "arrayTwo": [-1441, -124, -25, 1014, 1500, 660, 410, 245, 530]}
];
testCases.forEach(testCase => {
    console.log('TestCase:', testCase);
    console.log('Result:', smallestDifference(testCase.arrayOne, testCase.arrayTwo));
})
function binarySearch(S, item) {
    let startIndex = 0;
    let endIndex = S.length - 1;
    while (startIndex <= endIndex) {
        let middleIndex = Math.floor(startIndex + ((endIndex - startIndex) / 2));
        console.log('Index: ' + middleIndex + ' Value: ' + S[middleIndex]);
        if (S[middleIndex] < item) {
            startIndex = middleIndex + 1;
        } else if (S[middleIndex] > item) {
            endIndex = middleIndex - 1;
        } else {
            return middleIndex;
        }
    }
    return null;
}

let S = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let index = binarySearch(S, 10);
console.log('Result: ' + index);


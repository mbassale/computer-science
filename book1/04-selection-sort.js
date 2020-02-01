
function selectionSort(S) {
    for (let i = 0; i < S.length; i++) {
        let lowestIndex = i;
        for (let j = i + 1; j < S.length; j++) {
            if (S[j] < S[lowestIndex]) {
                lowestIndex = j;
            }
        }

        if (lowestIndex != i) {
            let temp = S[i];
            S[i] = S[lowestIndex];
            S[lowestIndex] = temp;
        }
    }
    return S;
}

console.log(selectionSort([4, 2, 7, 1, 3]));
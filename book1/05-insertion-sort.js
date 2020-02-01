
function insertionSort(S) {
    for (let i = 1; i < S.length; i++) {
        let position = i;
        let temp = S[i];
        while (position > 0 && S[position - 1] > temp) {
            S[position] = S[position - 1];
            position--;
        }
        S[position] = temp;
    }
    return S;
}


console.log(insertionSort([4, 2, 7, 1, 3]));
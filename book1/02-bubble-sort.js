function bubble_sort(S) {
    console.log('S:', S);
    let unsortedEndIndex = S.length - 1;
    let changes = null;
    do {
        changes = 0;
        for (let i = 0; i < unsortedEndIndex; i++) {
            if (S[i] > S[i + 1]) {
                let temp = S[i];
                S[i] = S[i + 1];
                S[i + 1] = temp;
                changes++;
            }
        }
        console.log('S:', S);
        unsortedEndIndex--;
    } while (changes > 0)
    return S;
}

let S = [4, 2, 7, 1, 3];
S = bubble_sort(S);
console.log('Sorted:', S);

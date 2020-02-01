
function hasDuplicates(S) {
    let existingNumbers = {};
    for (let i = 0; i < S.length; i++) {
        if (existingNumbers[S[i]] === undefined) {
            existingNumbers[S[i]] = 1;
        } else {
            return true;
        }
    }
    return false;
}

console.log('HasDuplicates:', hasDuplicates([1, 2, 3, 4, 5, 5, 6, 7, 8]));
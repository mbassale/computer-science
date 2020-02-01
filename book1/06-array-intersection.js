
function intersection(a1, a2) {
    let result = [];
    for (let i = 0; i < a1.length; i++) {
        for (let j = 0; j < a2.length; j++) {
            if (a1[i] == a2[j]) {
                result.push(a1[i]);
                break;
            }
        }
    }
    return result;
}

console.log(intersection([3, 1, 4, 2], [4, 5, 3, 6]));

function minNumberOfJumps(array) {
    if (array.length === 1) return 0;
    const jumps = new Array(array.length).fill(Infinity);
    jumps[0] = 0;
    for (let i = 1; i < array.length; i++) {
        for (let j = 0; j < i; j++) {
            if (array[j] + j >= i) {
                jumps[i] = Math.min(jumps[i], jumps[j] + 1);
            }
        }
    }
    return jumps[jumps.length - 1];
}

function minNumberOfJumps2(array) {
    if (array.length === 1) return 0;
    let jumps = 0;
    let maxReach = array[0];
    let steps = array[0];
    for (let i = 1;  i < array.length - 1; i++) {
        maxReach = Math.max(maxReach, array[i] + i);
        steps--;
        if (steps === 0) {
            jumps++;
            steps = maxReach - i;
        }
    }
    return jumps + 1;
}

const tests = [
    { array: [3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3], expected: 4 },
    { array: [2, 1, 2, 3, 1, 1, 1], expected: 3 }
];

for (const test of tests) {
    const result1 = minNumberOfJumps(test.array);
    const result2 = minNumberOfJumps2(test.array);
    console.log('array:', test.array, 'expected:', test.expected, 'result1:', result1, 'result2:', result2);
}

function threeNumberSort(array, order) {
    // O(1) time | O(1) space
    const orderCounts = {};
    for (let i = 0; i < order.length; i++) {
        orderCounts[order[i]] = 0;
    }

    // get number counts if number exists on order array
    // O(n) time | O(1) space
    for (let i = 0; i < array.length; i++) {
        const currentNumber = array[i];
        if (currentNumber in orderCounts) {
            orderCounts[currentNumber]++;
        }
    }

    // overwrite elements on array using orderCounts as base.
    // O(n) time | O(1) space
    let orderIndex = 0;
    for (let i = 0; i < array.length; i++) {
        if (orderCounts[order[orderIndex]] == 0) {
            i--;
            continue;
        }
        array[i] = order[orderIndex];
        orderCounts[order[orderIndex]]--;
        if (orderCounts[order[orderIndex]] == 0) {
            orderIndex++;
        }
    }

    return array;
}

function swap(i, j, array) {
    const temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

function threeNumberSort2(array, order) {
    // only three numbers, we execute two passes, one from left to right and other from right to left.
    const firstNumber = order[0];
    const lastNumber = order[1];

    let firstIndex = 0;
    for (let i = 0; i < array.length; i++) {
        if (array[i] === firstNumber) {
            swap(i, firstIndex, array);
            firstIndex++;
        }
    }

    let lastIndex = array.length - 1;
    for (let i = array.length - 1; i >= 0; i--) {
        if (array[i] === lastNumber) {
            swap(i, lastIndex, array);
            lastIndex--;
        }
    }

    return array;
}

function checkResult(result, expected) {
    let ok = result.length === expected.length;
    if (ok) {
        for (let i = 0; i < result.length && ok; i++) {
            ok = result[i] == expected[i];
        }
    }
    return ok;
}

const tests = [
    { array: [1, 0, 0, -1, -1, 0, 1, 1], order: [0, 1, -1], expected: [0, 0, 0, 1, 1, 1, -1, -1] },
    { array: [], order: [0, 7, 9], expected: [] },
    { array: [-2, -3, -3, -3, -3, -3, -2, -2, -3], order: [-2, -3, 0], expected: [-2, -2, -2, -3, -3, -3, -3, -3, -3] },
    { array: [7, 7, 7, 11, 11, 7, 11, 7], order: [11, 7, 9], expected: [11, 11, 11, 7, 7, 7, 7, 7] }
];

for (const test of tests) {
    const result1 = threeNumberSort(test.array.slice(), test.order);
    const ok1 = checkResult(result1, test.expected);
    const result2 = threeNumberSort2(test.array.slice(), test.order);
    const ok2 = checkResult(result2, test.expected);
    console.log('array:', test.array, 'order:', test.order, 'expected:', test.expected, 
        'result1:', result1, 'ok1:', ok1,
        'result2:', result2, 'ok2:', ok2);
}
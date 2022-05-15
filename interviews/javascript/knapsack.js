
function knapsackProblem(items, capacity) {
    // generate values matrix of (n + 1) x (capacity + 1) items
    const values = new Array(items.length + 1).fill(null);
    for (let i = 0; i <= items.length; i++) {
        values[i] = new Array(capacity + 1).fill(0);
    }
    
    // for each item
    for (let i = 1; i <= items.length; i++) {

        const currentValue = items[i - 1][0];
        const currentWeight = items[i - 1][1];

        // get maximum values for each capacity
        for (let j = 1; j <= capacity; j++) {

            if (currentWeight > j) {
                values[i][j] = values[i - 1][j];
            } else {
                const previousValue = values[i - 1][j];
                const newValue = currentValue + values[i - 1][j - currentWeight];
                values[i][j] = Math.max(newValue, previousValue);
            }

        }
    }

    // get indexes
    const maximumValue = values[items.length][capacity];
    const itemIndexes = [];
    let i = items.length;
    let j = capacity;
    while (i > 0) {
        if (values[i][j] > values[i - 1][j]) {
            itemIndexes.push(i - 1);
            j -= items[i - 1][1];
            i--;
        } else {
            i--;
        }
    }
    itemIndexes.reverse();

    return [maximumValue, itemIndexes];
}

const tests = [
    { items: [[1, 2], [4, 3], [5, 6], [6, 7]], capacity: 10, expected: [10, [1, 3]]},
    { items: [[2, 1], [70, 70], [30, 30], [69, 69], [100, 100]], capacity: 100, expected: [101, [0, 2, 3]]}
];

for (const test of tests) {
    const result = knapsackProblem(test.items, test.capacity);
    console.log('items:', test.items, 'capacity:', test.capacity, 'expected:', test.expected, 'result:', result);
}
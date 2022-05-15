
function arrayOfProducts(array) {
    const products = new Array(array.length).fill(0);
    const leftProducts = new Array(array.length).fill(1);
    const rightProducts = new Array(array.length).fill(1);

    let leftRunningProduct = 1;
    for (let i = 0; i < array.length; i++) {
        leftProducts[i] = leftRunningProduct;
        leftRunningProduct *= array[i];
    }

    let rightRunningProduct = 1;
    for (let i = array.length - 1; i >= 0; i--) {
        rightProducts[i] = rightRunningProduct;
        rightRunningProduct *= array[i];
    }

    for (let i = 0; i < array.length; i++) {
        products[i] = leftProducts[i] * rightProducts[i];
    }
    
    return products;
}

const tests = [
    { array: [5, 1, 4, 2], expected: [8, 40, 10, 20] },
    { array: [1, 8, 6, 2, 4], expected: [384, 48, 64, 192, 96] }
];

for (const test of tests) {
    const result = arrayOfProducts(test.array);
    console.log('array:', test.array, 'expected:', test.expected, 'result:', result);
}

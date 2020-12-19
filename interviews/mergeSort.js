const {performance} = require('perf_hooks');

function mergeSort(array) {
    if (array.length == 1) {
        return array;
    }
    const mid = Math.floor((array.length - 1) / 2);
    const array1 = array.slice(0, mid + 1);
    const array2 = array.slice(mid + 1, array.length);
    const sorted1 = mergeSort(array1);
    const sorted2 = mergeSort(array2);
    const combined = Array(sorted1.length + sorted2.length).fill(null);
    let i = 0; 
    let j = 0;
    let k = 0;
    while (i < sorted1.length || j < sorted2.length) {
        if (i < sorted1.length && j < sorted2.length) {
            if (sorted1[i] <= sorted2[j]) {
                combined[k] = sorted1[i];
                i++;
            } else {
                combined[k] = sorted2[j];
                j++;
            }
        } else if (i < sorted1.length && j >= sorted2.length) {
            combined[k] = sorted1[i];
            i++;
        } else if (j < sorted2.length && i >= sorted1.length) {
            combined[k] = sorted2[j];
            j++;
        }
        k++;
    }
    return combined;
}

function _doMerge(array, auxArray, leftIndex, mid, rightIndex) {
    let i = leftIndex;
    let j = mid + 1;
    let k = leftIndex;
    while (i <= mid || j <= rightIndex) {
        if (i <= mid && j <= rightIndex) {
            if (auxArray[i] <= auxArray[j]) {
                array[k] = auxArray[i];
                i++;
            } else {
                array[k] = auxArray[j];
                j++;
            }
        } else if (i <= mid && j > rightIndex) {
            array[k] = auxArray[i];
            i++;
        } else if (j <= rightIndex && i > mid) {
            array[k] = auxArray[j];
            j++;
        }
        k++;
    }
}

function _mergeSort(array, auxArray, leftIndex, rightIndex) {
    if (leftIndex == rightIndex) return;
    const mid = Math.floor((rightIndex - leftIndex) / 2.0) + leftIndex;
    _mergeSort(auxArray, array, leftIndex, mid);
    _mergeSort(auxArray, array, mid + 1, rightIndex);
    _doMerge(array, auxArray, leftIndex, mid, rightIndex);
}

function mergeSort2(array) {
    const auxArray = array.slice();
    _mergeSort(array, auxArray, 0, array.length - 1);
    return array;
}

function measure(array, func) {
    const startTime = performance.now();
    const result = func(array);
    const endTime = performance.now();
    return [endTime - startTime, result];
}

const tests = [
    { array: [8, 5, 2, 9, 5, 6, 3], expected: [2, 3, 5, 5, 6, 8, 9] },
];

for (const test of tests) {
    const [deltaTime1, result1] = measure(test.array.slice(), mergeSort);
    const [deltaTime2, result2] = measure(test.array.slice(), mergeSort2);
    console.log('array:', test.array, 'expected:', test.expected, 
        'result1:', result1, 'deltaTime1:', deltaTime1, 
        'result2:', result2, 'deltaTime2:', deltaTime2);
}

class QuickSort {

    array = null;

    constructor(array) {
        this.array = array;
    }

    sort(leftIndex, rightIndex) {
        if (rightIndex - leftIndex <= 0) return;
        let pivotPosition = this.partition(leftIndex, rightIndex);
        this.sort(leftIndex, pivotPosition - 1);
        this.sort(pivotPosition + 1, rightIndex);
    }

    partition(leftPointer, rightPointer) {
        let pivotPosition = rightPointer;
        let pivot = this.array[pivotPosition];

        rightPointer--;
        while (true) {

            while (this.array[leftPointer] < pivot) {
                leftPointer++;
            }

            while (this.array[rightPointer] > pivot) {
                rightPointer--;
            }

            if (leftPointer >= rightPointer) {
                break;
            } else {
                this.swap(leftPointer, rightPointer);
            }
        }

        this.swap(leftPointer, pivotPosition);
        return leftPointer;
    }

    swap(pointer1, pointer2) {
        let tempValue = this.array[pointer1];
        this.array[pointer1] = this.array[pointer2];
        this.array[pointer2] = tempValue;
    }
}

let array = [0, 5, 2, 1, 6, 3];
console.log('Unsorted:', array);
let quickSortImpl = new QuickSort(array);
quickSortImpl.sort(0, array.length - 1);
console.log('Sorted:', array);
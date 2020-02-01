
class SortableArray {

    array = null;

    constructor(array) {
        this.array = array;
    }

    quickSelect(kthLowestValue, leftIndex, rightIndex) {
        if (rightIndex - leftIndex <= 0) return this.array[leftIndex];
        let pivotPosition = this.partition(leftIndex, rightIndex);
        if (kthLowestValue < pivotPosition) {
            return this.quickSelect(kthLowestValue, leftIndex, pivotPosition - 1);
        } else if (kthLowestValue > pivotPosition) {
            return this.quickSelect(kthLowestValue, pivotPosition + 1, rightIndex);
        } else {
            return this.array[pivotPosition];
        }
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
let sortableArray = new SortableArray(array);
let secondToLowest = sortableArray.quickSelect(2, 0, array.length - 1);
console.log('Selected:', secondToLowest);
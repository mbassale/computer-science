import java.util.Random;

public class Example6ReverseArray {

    /**
     * Reverses an array.
     * Time: O(n)
     * Memory: O(1) in-place
     * 
     * @param <T>   array element type
     * @param array array to reverse
     */
    <T> void reverse(T[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            int other = array.length - i - 1;
            T temp = array[i];
            array[i] = array[other];
            array[other] = temp;
        }
    }

    void run() {
        Integer[] arr1 = new Integer[] { 1, 2, 3, 4, 5 };
        printArray("Array1: ", arr1);
        reverse(arr1);
        printArray("Array1 Reversed: ", arr1);
        Integer[] arr2 = new Integer[20];
        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = new Random().nextInt(100);
        }
        printArray("Array2: ", arr2);
        reverse(arr2);
        printArray("Array2 Reversed: ", arr2);
    }

    public static void main(String[] args) {
        new Example6ReverseArray().run();
    }

    <T> void printArray(String prefix, T[] arr) {
        System.out.print(prefix);
        for (T i : arr) {
            System.out.print(i);
            System.out.print(' ');
        }
        System.out.println();
    }
}
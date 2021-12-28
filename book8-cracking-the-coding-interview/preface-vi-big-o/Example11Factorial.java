public class Example11Factorial {

    /**
     * Factorial recursive.
     * Time: O(n)
     * Memory: O(n)
     * 
     * @param n number
     * @return n!
     */
    int factorialRecursive(int n) {
        if (n < 0) {
            return -1;
        } else if (n == 0) {
            return 1;
        } else {
            return n * factorialRecursive(n - 1);
        }
    }

    /**
     * Factorial iterative.
     * Time: O(n)
     * Memory: O(1)
     * 
     * @param n number
     * @return n!
     */
    int factorialIterative(int n) {
        int result = n--;
        while (n >= 1) {
            result *= n--;
        }
        return result;
    }

    void run() {
        long start = System.nanoTime();
        int result = factorialRecursive(15);
        long end = System.nanoTime();
        long delta = end - start;
        System.out.println("FactorialRecursive(10): " + result + " " + delta + "ns");
        start = System.nanoTime();
        result = factorialIterative(15);
        end = System.nanoTime();
        delta = end - start;
        System.out.println("FactorialIterative(10): " + result + " " + delta + "ns");
    }

    public static void main(String[] args) {
        new Example11Factorial().run();
    }
}

public class Example13NthFibonacci {

    /**
     * Calculates Nth Fibonacci number.
     * Time: O(2^n)
     * Memory: O(n)
     * 
     * @param n
     * @return
     */
    int fib(int n) {
        if (n <= 0)
            return 0;
        else if (n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }

    /**
     * Calculates Nth Fibonacci number with memoization.
     * Time: O(n)
     * Memory: O(n)
     * 
     * @param n
     * @param memo Array with cached fib() results
     * @return
     */
    int fib(int n, int[] memo) {
        if (n <= 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (memo[n] > 0)
            return memo[n];
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }

    void run() {
        for (int i = 0; i <= 40; i++) {
            int[] memo = new int[i + 1];
            for (int j = 0; j < memo.length; j++)
                memo[j] = 0;
            long start = System.nanoTime();
            int result = fib(i);
            float deltaInMS = (System.nanoTime() - start) / 1000000.0f;
            System.out.println(String.format("Fib(%d) = %d %.4fms", i, result, deltaInMS));
            start = System.nanoTime();
            result = fib(i, memo);
            deltaInMS = (System.nanoTime() - start) / 1000000.0f;
            System.out.println(String.format("FibMemoization(%d) = %d %.4fms", i, result, deltaInMS));
        }
    }

    public static void main(String[] args) {
        new Example13NthFibonacci().run();
    }
}

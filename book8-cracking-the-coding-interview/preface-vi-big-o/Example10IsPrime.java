public class Example10IsPrime {

    /**
     * Returns true if a number is prime.
     * Time: O(sqrt(N)) O(N^(1/2))
     * Memory: O(1)
     * 
     * @param n
     * @return
     */
    boolean isPrime(int n) {
        for (int x = 2; x * x <= n; x++) {
            if (n % x == 0)
                return false;
        }
        return true;
    }

    void run() {
        for (int i = 0; i <= 100; i++) {
            if (isPrime(i)) {
                System.out.println("IsPrime(" + i + ")");
            }
        }
    }

    public static void main(String[] args) {
        new Example10IsPrime().run();
    }
}

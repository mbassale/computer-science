package cl.mbassale.algorithmsSedgewick.ch1;

public class IsPrime {

    public static boolean isPrime(long n) {
        if (n < 2) return false;
        for (long i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    public static void main(String[] args) {
        for (long i = 0; i < 100; i++) {
            System.out.println("isPrime(" + i + ") = " + isPrime(i));
        }
    }
}

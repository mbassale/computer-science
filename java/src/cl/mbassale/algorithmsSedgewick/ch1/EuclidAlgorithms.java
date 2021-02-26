package cl.mbassale.algorithmsSedgewick.ch1;

public class EuclidAlgorithms {

    public static int gcd(int p, int q) {
        if (q == 0) return p;
        int r = p % q;
        return gcd(q, r);
    }

    public static void main(String[] args) {
        for (var i = 0; i < 100; i++) {
            for (var j = i + 1; j < 100; j++) {
                var res = gcd(j, i);
                if (res > 1) {
                    System.out.println("GCD(" + j + "," + i + ") = " + res);
                }
            }
        }
    }
}

package cl.mbassale.algorithmsSedgewick.ch1;

public class Sqrt {
    public static double sqrt(double c) {
        if (c < 0.0) return Double.NaN;
        double eps = 1e-15;
        double t = c;
        while (Math.abs(t - c / t) > eps * t) {
            t = (c/t + t) / 2.0;
        }
        return t;
    }

    public static void main(String[] args) {
        for (double i = 0; i < 100; i++) {
            System.out.println("Sqrt(" + i + ") = " + sqrt(i));
        }
    }
}

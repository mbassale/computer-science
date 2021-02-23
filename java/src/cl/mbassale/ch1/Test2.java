/**
 * Differences between int and double.
 */
package cl.mbassale.ch1;

class Test2 {
    public static void main(String[] args) {
        int v;
        double x;

        v = 10;
        x = 10.0;

        System.out.println("Original value of v: " + v);
        System.out.println("Original value of x: " + x);
        System.out.println();

        v = v / 4;
        x = x / 4;

        System.out.println("v after division: " + v);
        System.out.println("x after division: " + x);
    }
}
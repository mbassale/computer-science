package cl.mbassale.algorithmsSedgewick.ch1;

public class AbsoluteValue {
    public static int abs(int x) {
        if (x < 0) return -x;
        else return x;
    }

    public static void main(String[] args) {
        System.out.println("abs(-10) = " + abs(-10));
        System.out.println("abs(10)  = " + abs(10));
        System.out.println("abs(0)   = " + abs(0));
    }
}

package cl.mbassale.ch3;

public class ForLoopSum {
    public static void main(String[] args) {
        int sum = 0;
        for (int i = 1; i <= 100; sum += i++);
        System.out.println("Sum is " + sum);
    }
}

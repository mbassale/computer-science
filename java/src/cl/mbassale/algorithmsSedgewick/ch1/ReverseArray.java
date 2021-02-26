package cl.mbassale.algorithmsSedgewick.ch1;

public class ReverseArray {
    public static void main(String[] args) {
        int[] a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int N = a.length;
        for (var i = 0; i < N/2; i++) {
            var temp = a[i];
            a[i] = a[N - i - 1];
            a[N - i - 1] = temp;
        }
        System.out.print("Reversed array: ");
        for (var num : a) System.out.print(num + " ");
        System.out.println();
    }
}

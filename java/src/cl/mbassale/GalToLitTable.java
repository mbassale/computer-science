package cl.mbassale;

public class GalToLitTable {
    public static void main(String[] args) {
        int counter = 0;
        for (double gallons = 1; gallons <= 100; gallons++) {
            var liters = gallons * 3.7854;
            System.out.println(gallons + " gallons is " + liters + " liters.");
            counter++;
            if (counter % 10 == 0) {
                System.out.println();
            }
        }
    }
}

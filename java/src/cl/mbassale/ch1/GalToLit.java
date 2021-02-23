/**
 * Converts gallons to liters.
 */
package cl.mbassale.ch1;

public class GalToLit {
    public static void main(String[] args) {
        double gallons;
        double liters;

        gallons = 10;
        liters = gallons * 3.7854;
        System.out.println(gallons + " gallons is " + liters + " liters.");
    }
}

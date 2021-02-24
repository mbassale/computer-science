package cl.mbassale.ch3;

public class KeyboardInput {
    public static void main(String[] args) throws java.io.IOException {
        char ch;
        System.out.println("Press a key followed by ENTER: ");
        ch = (char) System.in.read();
        System.out.println("Your key is: " + ch);
    }
}

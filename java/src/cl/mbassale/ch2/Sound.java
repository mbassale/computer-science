package cl.mbassale.ch2;

public class Sound {
    public static void main(String[] args) {
        double time_interval = 7.2; // time in seconds to reach the sound to you
        double speed_of_sound = 1100; // 1,100 feet per second in air
        double distance_to_lighting = time_interval * speed_of_sound;
        System.out.println("The lighting is " + distance_to_lighting + " feet away.");
    }
}

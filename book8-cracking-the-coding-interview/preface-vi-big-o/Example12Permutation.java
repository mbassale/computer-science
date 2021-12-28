public class Example12Permutation {
    int permutation(String str) {
        return permutation(str, "", 0);
    }

    /**
     * Calculates the total permutations of character in the string str.
     * Time: O(n^2*n!)
     * Memory: O(n)
     * 
     * @param str
     * @param prefix
     * @param count
     * @return
     */
    int permutation(String str, String prefix, int count) {
        if (str.length() == 0) {
            return count + 1;
        } else {
            for (int i = 0; i < str.length(); i++) {
                String rem = str.substring(0, i) + str.substring(i + 1);
                count = permutation(rem, prefix + str.charAt(i), count);
            }
            return count;
        }
    }

    void run() {
        String[] testStrings = new String[] {
                "abcd",
                "abcde",
                "abcdef",
                "abcdefg",
                "abcdefgh",
                "abcdefghi",
                "abcdefghij",
                "abcdefghijk"
        };
        for (String testString : testStrings) {
            long startTime = System.nanoTime();
            int permutationCount = permutation(testString);
            float deltaTimeInMS = (System.nanoTime() - startTime) / 1000000.0f;
            System.out.println(String.format("%s: %d %.2fms", testString, permutationCount, deltaTimeInMS));
        }

    }

    public static void main(String[] args) {
        new Example12Permutation().run();
    }
}

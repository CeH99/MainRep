public class Main {
    public static void main(String[] args) {
        ClumpCounter cc = new ClumpCounter();

        System.out.println("Test 1: " + (cc.countClumps(new int[]{1, 2, 2, 3, 4, 4}) == 2));
        System.out.println("Test 2: " + (cc.countClumps(new int[]{1, 1, 2, 1, 1}) == 2));
        System.out.println("Test 3: " + (cc.countClumps(new int[]{1, 1, 1, 1, 1}) == 1));
        System.out.println("Test 4: " + (cc.countClumps(new int[]{1, 2, 3, 4, 5}) == 0));
        System.out.println("Test 5: " + (cc.countClumps(new int[]{1, 1, 2, 2, 3, 3}) == 3));
    }
}

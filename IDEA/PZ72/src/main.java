public class main {
    public static void main(String[] args) {
        NotReplace nr = new NotReplace();

        System.out.println("Test 1: " + nr.notReplace("is test"));
        System.out.println("Test 2: " + nr.notReplace("is-is"));
        System.out.println("Test 3: " + nr.notReplace("This is right"));
        System.out.println("Test 4: " + nr.notReplace("This is good"));
        System.out.println("Test 5: " + nr.notReplace("is"));
    }
}

public class Main {
    public static void main(String[] args) {
        Task task = new Task();

        // Завдання 1
        String input1 = "Chocolate";
        int n1 = 2;
        String result1 = task.frontTimes(input1, n1);
        System.out.println("Input: \"" + input1 + "\", " + n1);
        System.out.println("Output: \"" + result1 + "\"");

        String input2 = "Application";
        int n2 = 4;
        String result2 = task.frontTimes(input2, n2);
        System.out.println("Input: \"" + input2 + "\", " + n2);
        System.out.println("Output: \"" + result2 + "\"");

        String input3 = "Ab";
        int n3 = 3;
        String result3 = task.frontTimes(input3, n3);
        System.out.println("Input: \"" + input3 + "\", " + n3);
        System.out.println("Output: \"" + result3 + "\"");

        // Завдання 2
        double x = 0; // або 6, якщо ви хочете перевірити інше значення
        double y = task.calcY(x);
        System.out.println("x = " + x + ", y = " + y);
    }
}

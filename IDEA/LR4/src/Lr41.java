import java.util.Scanner;
public class Lr41 {

    public static void main(String[] args) {
        String input1 = "Приклад: з* різними% символами!%";
        String input2 = "I do not want to learn English, I want to study Java!! I do not 0990 want to learn007* history, I911 want to study765 Java!";
        String input3 = "Приклад&*( з %різними% символами^ номер два!";

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter string: ");
        String input4 = scanner.nextLine();

        System.out.println("\tYour strings:");
        System.out.printf("%s\n", input1);
        System.out.printf("%s\n", input2);
        System.out.printf("%s\n", input3);
        System.out.printf("%s\n\n", input4);

        System.out.println("\tCleared strings:");
        System.out.printf("%s\n", task1(input1));
        System.out.printf("%s\n", task1(input2));
        System.out.printf("%s\n", task1(input3));
        System.out.printf("%s\n", task1(input4));
    }

    public static String task1(String input) {
        String cleaned = "";

        for (char c : input.toCharArray()) {
            if (Character.isLetter(c) || Character.isSpaceChar(c)) {
                cleaned += c;
            }
        }
        return cleaned;
    }
}

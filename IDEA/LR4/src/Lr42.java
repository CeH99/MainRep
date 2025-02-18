import java.io.FileWriter;
import java.util.Scanner;
public class Lr42 {
    public static void main(String[] args) {
        String[] text = {
                "aBc#123$DfG!",
                "Xy7&*9Qw@Rz1",
                "9fH$L*oT!56K^",
                "QwErT1234*&@!",
                "78YhG$%Xz1!Ab",
                "f@45k#j1pQwe^3@zL99m_t!x",
                "Zx21%@p*9&d$h0n!q@5r_tyU"

        };
        FileWriter writer = new FileWriter(("file.txt"));
        writer.write
        Scanner scanner = new Scanner(System.in);
        System.out.println("\tText:");
        for (String str : text) {
            System.out.printf("%s\n", str);
        }
        System.out.println();
        //input
        System.out.print("Enter first symbol:");
        char firstChar = scanner.next().charAt(0);

        System.out.print("Enter second symbol:");
        char secondChar = scanner.next().charAt(0);

        //task2
        System.out.println("\n\tIndexes of these characters\n");
        System.out.printf("%s", task2(text, firstChar, secondChar));

        //task3
        task3(text, firstChar, secondChar);
        System.out.println("\n\tText after swap\n");
        for (String str : text) {
            System.out.printf("%s\n", str);
        }

    }
    public static String task2(String[] array, char firstChar, char secondChar) {
        String result = "";
        for (int i = 0; i < array.length; i++) {
            String currentString = array[i];
            for (int j = 0; j < currentString.length(); j++) {
                char currentChar = currentString.charAt(j);
                if (currentChar == firstChar || currentChar == secondChar) {
                    result += "In string number " + (i+1) + ", Char index: " + j + ", Char: " + currentChar + "\n";
                }
            }
        }
        return result;
    }
    public static String[] task3(String[] array, char char1, char char2) {
        int char1Index = -1;
        int char2Index = -1;
        for (int i = 0; i < array.length; i++) {
            if (array[i] != null && array[i].indexOf(char1) != -1 && char1Index == -1) {
                char1Index = i;
            }
            if (array[i] != null && array[i].indexOf(char2) != -1 && char2Index == -1) {
                char2Index = i;
            }
        }
        if (char1Index != -1 && char2Index != -1) {
            array[char1Index] = array[char1Index].replaceFirst(String.valueOf(char1), String.valueOf(char2));
            array[char2Index] = array[char2Index].replaceFirst(String.valueOf(char2), String.valueOf(char1));
        }
        return array;
    }

}

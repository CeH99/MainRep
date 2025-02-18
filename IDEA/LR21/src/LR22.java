import java.util.Scanner;
public class LR22 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\t Point coordinates\n");
        System.out.print("Enter x: ");
        double x = scanner.nextDouble();

        System.out.print("Enter y: ");
        double y = scanner.nextDouble();
        task3(x, y);
        System.out.println("\n--------------------------------------------\n");
        int a = 3;
        int b = 4;
        int c = 5;
        task4(3, 4, 5);

        task4(3, 5, 4);

        task4(3, 8, 11);

        task4(13, 5, 12);
    }

    public static void task3(double x, double y) {
        int position;

        if (x > 0 && y > 0) {
            position = 1;
        } else if (x < 0 && y > 0) {
            position = 2;
        } else if (x < 0 && y < 0) {
            position = 3;
        } else if (x > 0 && y < 0) {
            position = 4;
        } else if (x == 0 && y != 0) {
            position = 5;
        } else if (y == 0 && x != 0) {
            position = 6;
        } else {
            position = 7;
        }

        switch (position) {
            case 1:
                System.out.println("Its in first quarter.");
                break;
            case 2:
                System.out.println("Its in second quarter.");
                break;
            case 3:
                System.out.println("Its in third quarter.");
                break;
            case 4:
                System.out.println("Its in fourth quarter.");
                break;
            case 5:
                System.out.println("It lies on the y axis.");
                break;
            case 6:
                System.out.println("It lies on the x axis.");
                break;
            case 7:
                System.out.println("Its at the origin.");
                break;
            default:
                System.out.println("Unknown position.");
        }
    }


    public static void task4(int a, int b, int c) {
        if (Math.pow(c, 2) == Math.pow(a, 2) + Math.pow(b, 2)) {
            System.out.printf("Numbers %d, %d and %d are pythagorean triple\n", a, b, c);
        } else {
            System.out.printf("Numbers %d, %d and %d arent pythagorean triple\n", a, b, c);
        }
    }
}
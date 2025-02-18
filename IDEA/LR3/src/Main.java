import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        double min = 3.5;
        double max = 10.5;
        double step = 0.2;
        System.out.println("x\t y=f(x)\t z=f(x)");
        task1(min, max, step);
//-----------------------------------------------------------------------------------------------
        double[] arr1 = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10.1};
        double[] arr2 = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};

        System.out.println("Послідовність 1:");
        task21(arr1);
        System.out.printf("Результат для послідовності 1: %.1f%n\n", task2(arr1));

        System.out.println("Послідовність 2:");
        task21(arr2);
        System.out.printf("Результат для послідовності 2: %.1f%n\n", task2(arr2));
//-----------------------------------------------------------------------------------------------
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введіть значення x1: ");
        double x1 = scanner.nextDouble();

        System.out.print("Введітьзначення x2: ");
        double x2 = scanner.nextDouble();

        System.out.printf("Результат для x1 = %.4f: y = %.4f%n", x1, task3(x1));
        System.out.printf("Результат для x2 = %.4f: y = %.4f%n", x2, task3(x2));
    }

    public static void task1(double min, double max, double step) {
        for (double x = min; x < max; x += step) {
            double answer1 = Math.cos(1.5 * x) * Math.log10(2.5 * x);
            double answer2 = Math.sin(x) / Math.exp(1.0 / Math.sqrt(x));

            System.out.printf("%.1f  %.4f  %.4f\n", x, answer1, answer2);
        }
    }

    public static double task2(double[] arr) {
        double sum = 0.0;
        for (int i = 0; i < arr.length - 1; i++) {
            sum += arr[i] * arr[i + 1];
        }
        return sum;
    }

    public static void task21(double[] arr) {
        for(int i = 0; i < 10; i++ )
        {
            System.out.printf("%.1f  ", arr[i]);
        }
        System.out.println("\n");
    }

    public static double task3(double x) {
        double sum = 0;

        for (int i = 1; i <= 5; i++) {
            // (-1)^(i+1) * sin(sin(x)^i)
            double a = Math.pow(-1, i + 1) * Math.sin(Math.pow(Math.sin(x), i));

            // (2i - 1)
            int n = 2 * i - 1;
            int b = 1;
            while (n > 1) {
                b *= n;
                n--;
            }

            sum += a / b;
        }
        return sum;
    }

}


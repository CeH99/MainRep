public class LR21 {
    public static void main(String[] args) {
        double a = 0.5, b = 1.5, c = 3.2;

        double x1 = -2.3;
        double x2 = 0.6;
        double x3 = 4.8;
        double e2x = Math.exp(2*x1);
        System.out.printf("Результат для x1 = %.1f: %.4f\n", x1, task1(a, b, c, x1));
        System.out.printf("Результат для x2 = %.1f: %.4f\n", x2, task1(a, b, c, x2));
        System.out.printf("Результат для x3 = %.1f: %.4f\n", x3, task1(a, b, c, x3));

        System.out.println("\n--------------------------------------------------\n");

        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y1=%.4f%n", 1.2, 7.2, Math.exp(x1), task2(1.2, 7.2, Math.exp(x1), x1));
        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y2=%.4f%n", 1.2, 7.2, Math.exp(x2), task2(1.2, 7.2, Math.exp(x2), x2));
        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y3=%.4f%n\n", 1.2, 7.2, Math.exp(x3), task2(1.2, 7.2, Math.exp(x3), x3));

        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y1=%.4f%n", -1.5, 3.2, Math.exp(2*x1), task2(-1.5, 3.2, e2x, x1));
        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y2=%.4f%n", -1.5, 3.2, Math.exp(2*x2), task2(-1.5, 3.2, Math.exp(2*x2), x2));
        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y3=%.4f%n\n", -1.5, 3.2, Math.exp(2*x3), task2(-1.5, 3.2, Math.exp(2*x3), x3));

        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y1=%.4f%n", 1.7, 5.5, Math.exp(3), task2(1.7, 5.5, Math.exp(3), x1));
        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y2=%.4f%n", 1.7, 5.5, Math.exp(3), task2(1.7, 5.5, Math.exp(3), x2));
        System.out.printf("Для a=%.2f, b=%.2f, z=%.2f: y3=%.4f%n\n", 1.7, 5.5, Math.exp(3), task2(1.7, 5.5, Math.exp(3), x3));
    }

    public static double task1(double a, double b, double c, double x) {
        double result;
        double sumAB = a + b;

        if (sumAB > x) {
            result = Math.sin(Math.exp(a + b)) + Math.pow(x, 2);
        } else if (sumAB == x) {
            result = Math.atan(a * b * c) + Math.cbrt(x);
        } else {
            result = Math.asin(Math.pow(Math.cos(Math.sqrt(Math.abs(x))), 2));
        }

        return result;
    }

    public static double task2(double a, double b, double z, double x) {
        double y;
        int caseNumber;

        if (x < Math.pow(a, 3)) {
            caseNumber = 1;
        } else if (Math.pow(a, 3) <= x && x <= b) {
            caseNumber = 2;
        } else {
            caseNumber = 3;
        }

        switch(caseNumber) {
            case 1:
                y = a * Math.pow(Math.sin(x), 2) + b * Math.cos(z * x + a);
                break;
            case 2:
                y = Math.pow((a + b * x), 2) - Math.sin(a + z * x);
                break;
            case 3:
                y = Math.sqrt(x - Math.sin(b * x + z));
                break;
            default:
                y = 0;
        }

        return y;
    }
}

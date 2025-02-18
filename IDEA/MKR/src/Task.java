public class Task {

    // Метод для задачі 1
    public String frontTimes(String str, int n) {
        String front = str.length() < 3 ? str : str.substring(0, 3);
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < n; i++) {
            result.append(front);
        }
        return result.toString();
    }

    // Метод для задачі 2
    public double calcY(double x) {
        double sum = 0;

        for (int k = 1; k <= 5; k++) {
            if (k != 3) {
                double term = Math.pow(-1, k) * Math.pow(x + 3, k + 2) / factorial(k);
                sum += term;
            }
        }

        return sum;
    }

    // Метод для обчислення факторіалу
    private long factorial(int n) {
        long result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}

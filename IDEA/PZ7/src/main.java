public class main {
    public static void main(String[] args) {
        DigitSum digitSum = new DigitSum();

        // Тест 1: Сума цифр у "aa1bc2d3" повинна дорівнювати 6
        if (digitSum.sumDigits("aa1bc2d3") == 6) {
            System.out.println("Test 1 passed");
        } else {
            System.out.println("Test 1 failed");
        }

        // Тест 2: Сума цифр у "aa11b33" повинна дорівнювати 8
        if (digitSum.sumDigits("aa11b33") == 8) {
            System.out.println("Test 2 passed");
        } else {
            System.out.println("Test 2 failed");
        }

        // Тест 3: У "Chocolate" немає цифр, тому результат має бути 0
        if (digitSum.sumDigits("Chocolate") == 0) {
            System.out.println("Test 3 passed");
        } else {
            System.out.println("Test 3 failed");
        }

        // Тест 4: Сума цифр у "12345" повинна дорівнювати 15
        if (digitSum.sumDigits("12345") == 15) {
            System.out.println("Test 4 passed");
        } else {
            System.out.println("Test 4 failed");
        }

        // Тест 5: Порожній рядок повинен повернути 0
        if (digitSum.sumDigits("") == 0) {
            System.out.println("Test 5 passed");
        } else {
            System.out.println("Test 5 failed");
        }
    }
}


public class Main {
    public static void main(String[] args) {
        Interval interval1 = new Interval(1, 5);
        Interval interval2 = new Interval(3, 7);

        System.out.println("Інтервал 1: " + interval1);
        System.out.println("Інтервал 2: " + interval2);
        System.out.println("Довжина інтервалу 1: " + interval1.length());

        interval1.shift(2);
        System.out.println("Зміщений інтервал 1: " + interval1);

        interval2.scale(2);
        System.out.println("Розтягнутий інтервал 2: " + interval2);

        Interval sumInterval = interval1.add(interval2);
        System.out.println("Сума інтервалів: " + sumInterval);

        Interval diffInterval = interval1.subtract(interval2);
        System.out.println("Різниця інтервалів: " + diffInterval);
    }
}
